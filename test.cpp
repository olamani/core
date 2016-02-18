#include <iostream>
#include "Connection.hpp"

int main() {
    olamani::Connection connection("127.0.0.1", 8888);
    if (connection.connect()) {
        if (connection.send("Hello world!")) {
            std::cout << connection.receive() << std::endl;
        } else {
            std::cerr << "main -> Error sending" << std::endl;
        }
        connection.disconnect();
    } else {
        std::cerr << "main -> Error connecting to server" << std::endl;
    }
    return 0;
}
