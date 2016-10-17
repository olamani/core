#include <thread>
#include <iostream>
#include "Loop.hpp"
#include "Connection.hpp"

namespace Olamani {

namespace Loop {

std::thread thread;
bool running = false;
Connection* connection = 0;

void parseMessage(std::string message) {
    std::cout << message << std::endl;
}

void run() {
    while (running) {
        parseMessage(connection->receive());
    }
}

void setConnection(Connection* _connection) {
    connection = _connection;
}

void start() {
    running = true;
    thread = std::thread(run);
}

void stop() {
    running = false;
    connection->send("(bye)");
    connection->disconnect();
    thread.join();
}

} // namespace Loop

} // namespace Olamani