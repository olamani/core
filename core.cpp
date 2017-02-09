#include <iostream>
#include <thread>
#include <chrono>
#include "Controller.hpp"

int main() {
    Olamani::Controller::connect();
    std::cout << "Connected" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(60));
    Olamani::Controller::disconnect();
    std::cout << "Disconnected" << std::endl;
    return 0;
}