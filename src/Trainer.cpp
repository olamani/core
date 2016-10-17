#include "Trainer.hpp"
#include <string>

namespace Olamani {

namespace Trainer {

enum TokenType {
    NAME,
    INT,
    OP,
    CP
}

struct Token {
    std::string value;
    TokenType type;
};

std::string script;
int position;
Token token;

/*** functions ***/

bool isSpace() {
    
}

Token nextToken() {
    
}

void consume() {
    token = nextToken();
}

bool matchOpenParenthesis() {
    if (script[position] == '(') {
        consume();
        return true;
    } else {
        return false;
    }
}

bool matchCloseParenthesis() {
    if (script[position] == ')') {
        consume();
        return true;
    } else {
        return false;
    }
}

bool matchFunctionName() {
    return false;
}

bool matchArgument() {
    return false;
}

bool matchExpression() {
    if (!matchOpenParenthesis()) return false;
    //matchFunctionName();
    //while (matchArgument());
    if (!matchCloseParenthesis()) return false;
    return true;
}

void loadScript(std::string filepath) {

}

bool parseScript(std::string _script) {
    script = _script;
    return matchExpression();
}

void reset() {
    script = "";
    position = 0;
}

void onNewCycle(int time) {
    
}

} // namespace Trainer

} // namespace Olamani