#include <string>
#include <cctype>
#include "Lexer.hpp"

namespace Olamani {

Lexer::Lexer(std::string stream) {
    this->stream = stream;
    position = 0;
}

Lexer::~Lexer() {

}

void Lexer::reset() {
    stream = "";
    position = 0;
}

void Lexer::consume() {
    position++;
}

Token Lexer::next() {
    Token token;
    while (isSpace()) {
        position++;
    }
    if (isLeftPar()) {
        token.type = LP;
        token.value = "(";
        return token;
    }
    if (isRightPar()) {
        token.type = RP;
        token.value = ")";
        return token;
    }
    if (isAlpha()) {
        int start = position;
        do {
            position++;
        } while (isAlphaNumeric());
        std::string value = stream.substr(start, position - start);
        position--;
        token.type = IDENTIFIER;
        token.value = value;
        return token;
    }
    if (isNumeric()) {
        int start = position;
        do {
            position++;
        } while (isNumeric());
        std::string value = stream.substr(start, position - start);
        position--;
        token.type = NUMBER;
        token.value = value;
        return token;
    }
    if (isEOL()) {
        token.type = END;
        token.value = "";
        return token;
    }
    std::string remainder = stream.substr(position);
    token.type = ERROR;
    token.value = remainder;
    return token;
}

bool Lexer::isEOL() {
    return position == stream.length();
}

bool Lexer::isSpace() {
    return !isEOL() && stream[position] == ' '; 
}

bool Lexer::isLeftPar() {
    return !isEOL() && stream[position] == '(';
}

bool Lexer::isRightPar() {
    return !isEOL() && stream[position] == ')';
}

bool Lexer::isAlpha() {
    return !isEOL() && isalpha(stream[position]);
}

bool Lexer::isAlphaNumeric() {
    return !isEOL() && isalnum(stream[position]);
}

bool Lexer::isNumeric() {
    return !isEOL() && isdigit(stream[position]);
}


} // namespace Olamani