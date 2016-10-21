#ifndef PARSER_HPP
#define PARSER_HPP

#include "Lexer.hpp"
#include <string>
#include <vector>

namespace Olamani {

struct List {
    TokenType type;
    std::string value;
    std::vector<std::shared_ptr<List> > arguments;
    std::string toString();
    int size();
};

class Parser {
private:
    Lexer lexer;
    std::shared_ptr<List> matchArgument();
public:
    Parser(std::string stream): lexer(stream) {};
    ~Parser() {};
    std::shared_ptr<List> matchExpression();
};

}

#endif // PARSER_HPP