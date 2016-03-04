#ifndef PARSER_HPP
#define PARSER_HPP

#include "Connection.hpp"

namespace Olamani {

namespace Parser {

void setConnection(Connection* connection);
void start();
void stop();

}

} // namespace Olamani

#endif // PARSER_HPP
