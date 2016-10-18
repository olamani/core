#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Lexer.hpp"

BOOST_AUTO_TEST_CASE(lexer_test) {
    Olamani::Lexer lexer("  ( ) ) 1234 abcd ABCD ABC123");
    // Check (
    Olamani::Token token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::LP, token.type);
    lexer.consume();
    // Check )
    token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::RP, token.type);
    lexer.consume();
    // check )
    token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::RP, token.type);
    lexer.consume();
    // check 1234
    token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::NUMBER, token.type);
    BOOST_CHECK_EQUAL("1234", token.value);
    lexer.consume();
    // check abcd
    token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::IDENTIFIER, token.type);
    BOOST_CHECK_EQUAL("abcd", token.value);
    lexer.consume();
    // check ABCD
    token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::IDENTIFIER, token.type);
    BOOST_CHECK_EQUAL("ABCD", token.value);
    lexer.consume();
    // check ABC123
    token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::IDENTIFIER, token.type);
    BOOST_CHECK_EQUAL("ABC123", token.value);
    lexer.consume();
    // check END
    token = lexer.next();
    BOOST_CHECK_EQUAL(Olamani::END, token.type);
}