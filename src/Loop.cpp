#include <thread>
#include <iostream>
#include <regex>
#include "Controller.hpp"
#include "Loop.hpp"
#include "Connection.hpp"
#include "Body.hpp"
#include "DSL.hpp"
#include "Server.hpp"

namespace Olamani {

namespace Loop {

std::thread thread;
bool running = false;
Connection* connection = 0;

void parseMessage(std::string message) {
    std::cout << message << std::endl;
    size_t found = message.find_first_of(" ");
    std::string message_type = message.substr(1, found - 1);
    if (message_type.compare("sense_body") == 0) {
        Body::sendMessage(message);
    } else if (message_type.compare("hear") == 0) {

    } else if (message_type.compare("see") == 0) {

    } else {
        std::cerr << "Message not recognized " << message << std::endl;
    }
}

void run() {
    while (running) {
        parseMessage(connection->receive());
    }
}

void setConnection(Connection* connection_) {
    connection = connection_;
}

void start() {
    std::string message = "(init " + Body::TEAM_NAME + " (version 15.1)";
    switch (Controller::type) {
        case Controller::PLAYER:
            message = message + ")";
            break;
        case Controller::GOALIE:
            message = message + " (goalie))";
            break;
    }
    // Connect to server
    connection->send(message);
    std::string response = connection->receive();
    std::smatch match;
    /*if (std::regex_match(response, match, std::regex("\\(init\\s+(l|r)\\s+(\\d+)\\s+([\\w\\_]+)\\)"))) {
        std::string side = match[1].str();
        Body::SIDE = side[0];
        Body::UNIFORM_NUMBER = std::stoi(match[2]);
    }*/
    // Receive server parameters
    response = connection->receive();
    Server::handleServerParameters(response);
    // Receive player parameters
    response = connection->receive();
    Body::handleParametersMessage(response);
    for (int i = 0; i < Body::PLAYER_TYPES; i++) {
        response = connection->receive();
        Body::handlePlayerTypeMessage(response);
    }
    // Synchronize see
    connection->send("(synch_see)");
    // Start handlers
    Body::start();
    // Loop
    running = true;
    thread = std::thread(run);
}

void stop() {
    running = false;
    connection->send("(bye)");
    connection->disconnect();
    thread.join();
    // Stop handlers
    Body::stop();
}

} // namespace Loop

} // namespace Olamani
