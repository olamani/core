#include <iostream>
#include "Connection.hpp"

int main() {
	Olamani::Connection connection("localhost", 6000);
	if (connection.connect()) {
		connection.send("(init olamani (version 15.1))");
		for (int i = 0; i < 100; i++) {
			std::cout << connection.receive() << std::endl;
		}
		connection.send("(bye)");
		connection.disconnect();
	} else {
		std::cerr << "Error connecting" << std::endl;
	}
    return 0;
}
