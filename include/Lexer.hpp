#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

namespace Olamani {

enum TokenType {
    END,
    NUMBER,
    IDENTIFIER,
    LP,
    RP,
    ERROR
};

struct Token {
    std::string value;
    TokenType type;
};

class Lexer {
private:
    int position;
    std::string stream;
    bool isEOL();
    bool isSpace();
    bool isLeftPar();
    bool isRightPar();
    bool isAlpha();
    bool isAlphaNumeric();
    bool isNumeric();
public:
    Lexer(std::string stream);
    ~Lexer();
    void reset();
    void consume();
    Token next();
};

} // namespace Olamani

#endif // LEXER_HPP