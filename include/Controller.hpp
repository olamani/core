#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>

namespace Olamani {

namespace Controller {

enum AgentType {
    PLAYER,
    GOALIE
};

extern AgentType   type;

void connect();
void disconnect();

} // namespace Controller

} // namespace Olamani

#endif // CONTROLLER_HPP