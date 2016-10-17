#include "Controller.hpp"

#include <string>

namespace Olamani {

namespace Controller {

bool connected = false;
std::string host = "localhost";
int port = 6000;
AgentType type = PLAYER;

void setHost(std::string _host) {
    host = _host;
}

void setPort(int _port) {
    port = _port;
}

void setAgentType(AgentType _type) {
    type = _type;
}

void reset() {
    if (!connected) {
        host = "localhost";
        port = 6000;
        type = PLAYER;
    }
}

void connect() {

}

void disconnect() {

}

} // namespace Controller

} // namespace Olamani