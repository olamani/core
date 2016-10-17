#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Trainer.hpp"

BOOST_AUTO_TEST_CASE(empty_expression) {
    Olamani::Trainer::reset();
    std::string script = "()";
    BOOST_CHECK_EQUAL(true, Olamani::Trainer::parseScript(script));
}