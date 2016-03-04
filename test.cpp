#include <iostream>
#include <thread>
#include <chrono>
#include "Connection.hpp"
#include "Parser.hpp"

int main() {
    Olamani::Connection connection("localhost", 8888);
    if (connection.connect()) {
        Olamani::Parser::setConnection(&connection);
        Olamani::Parser::start();
        for (int i = 0; i < 10; ++i) {
            connection.send("Ping");
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        Olamani::Parser::stop();
        connection.disconnect();
    }

}
