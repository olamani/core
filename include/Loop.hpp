#ifndef LOOP_HPP
#define LOOP_HPP

#include "Connection.hpp"

namespace Olamani {

namespace Loop {

void setConnection(Connection* connection);
void start();
void stop();

}

} // namespace Olamani

#endif // LOOP_HPP
