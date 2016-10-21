#include "Parser.hpp"
#include <iostream>

namespace Olamani {

std::string List::toString() {
    if (type == LIST) {
        std::string list = "";
        for (auto it = arguments.begin(); it != arguments.end(); ++it) {
            list = list + (*it)->toString();
        }
        return list;
    } else {
        return value;
    }
}

int List::size() {
    return arguments.size();
}

std::shared_ptr<List> Parser::matchArgument() {
    Token token = lexer.next();
    std::shared_ptr<List> list = std::make_shared<List>();
    if (token.type == LP) {
        return matchExpression();
    } else if (token.type == NUMBER) {
        list->type = NUMBER;
        list->value = token.value;
        lexer.consume();
        return list;
    } else if (token.type == IDENTIFIER) {
        list->type = IDENTIFIER;
        list->value = token.value;
        lexer.consume();
        return list;
    } else {
        list->type = ERROR;
        list->value = token.value;
        return list;
    }
}

std::shared_ptr<List> Parser::matchExpression() {
    std::shared_ptr<List> list = std::make_shared<List>();
    Token token = lexer.next();
    if (token.type == LP) {
        list->type = LIST;
        list->value = "";
        lexer.consume();
        token = lexer.next();
        while (token.type != RP) {
            std::shared_ptr<List> arg = matchArgument();
            if (arg->type == ERROR) {
                return arg;
            }
            (list->arguments).push_back(arg);
            //std::cout << list->arguments.size() << std::endl;
            token = lexer.next();
        }
        if (token.type == RP) {
            lexer.consume();
            return list;
        } else {
            list->type = ERROR;
            return list;
        }
    } else {
        list->type = ERROR;
        return list;
    }
}

}