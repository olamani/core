#include <iostream>
#include "include/Connection.hpp"

int main() {
    olamani::Connection connection("127.0.0.1", 8888);
    if (connection.connect()) {
        connection.send("Hello world!");
        std::cout << connection.receive() << std::endl;
    } else {
        std::cerr << "Error connecting to server" << std::endl;
    }
    return 0;
}
