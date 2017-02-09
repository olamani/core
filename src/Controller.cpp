#include "Controller.hpp"

#include <string>
#include "Body.hpp"
#include "Loop.hpp"
#include "Connection.hpp"

namespace Olamani {

namespace Controller {

AgentType   type = PLAYER;
Connection  connection("localhost", 6000);

void connect() {
    Body::TEAM_NAME = "Olamani";
    connection.connect();
    Loop::setConnection(&connection);
    Loop::start();
}

void disconnect() {
    Loop::stop();
}

} // namespace Controller

} // namespace Olamani