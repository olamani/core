#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Parser.hpp"
#include <string>
#include <iostream>

BOOST_AUTO_TEST_CASE(parser_test_success) {
    std::string stream = "(function abc 123)";
    Olamani::Parser parser(stream);
    std::shared_ptr<Olamani::List> list = parser.matchExpression();
    BOOST_CHECK_EQUAL(Olamani::LIST, list->type);
    BOOST_CHECK_EQUAL(3, list->arguments.size());
}

BOOST_AUTO_TEST_CASE(parser_test_fails) {
    std::string stream = "function abc 123)";
    Olamani::Parser parser(stream);
    std::shared_ptr<Olamani::List> list = parser.matchExpression();
    BOOST_CHECK_EQUAL(Olamani::ERROR, list->type);
}

BOOST_AUTO_TEST_CASE(parser_test_recursive_success) {
    std::string stream = "(function (another abc) 123)";
    Olamani::Parser parser(stream);
    std::shared_ptr<Olamani::List> list = parser.matchExpression();
    BOOST_CHECK_EQUAL(Olamani::LIST, list->type);
    BOOST_CHECK_EQUAL(3, list->arguments.size());
    std::shared_ptr<Olamani::List> nested = list->arguments.at(1);
    BOOST_CHECK_EQUAL(Olamani::LIST, nested->type);
    BOOST_CHECK_EQUAL(2, nested->arguments.size());
}

/*BOOST_AUTO_TEST_CASE(parser_test_recursive_fails) {
    std::string stream = "(function ((another abc) 123)";
    Olamani::Parser parser(stream);
    BOOST_CHECK_EQUAL(false, parser.matchExpression());
}

BOOST_AUTO_TEST_CASE(parser_test_long_recursive_success) {
    std::string stream = "(function (another abc (list 1) (list 2) ((list 3) 4)) 123)";
    Olamani::Parser parser(stream);
    BOOST_CHECK_EQUAL(true, parser.matchExpression());
}*/