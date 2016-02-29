#include <thread>
#include <iostream>
#include "Connection.h"

namespace Olamani {

namespace Parser {

std::thread thread;
bool running = false;
Connection* connection = 0;

void run() {
    while (running) {
        parseMessage(connection->receiveMessage());
    }
}

void start() {
    running = true;
    thread = std::thread(run);
}

void stop() {
    running = false;
    connection->sendMessage("(bye)");
    connection->disconnect();
    thread.join();
}

} // namespace Parser

} // namespace Olamani
