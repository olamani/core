#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>

namespace Olamani {

namespace Controller {

enum AgentType {
    PLAYER,
    GOALIE,
    COACH,
    TRAINER
}

void setHost(std::string host);
void setPort(int port);
void setAgentType(AgentType type);
void reset();
void connect();
void disconnect();

} // namespace Controller

} // namespace Olamani

#endif // CONTROLLER_HPP