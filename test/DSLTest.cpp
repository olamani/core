#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "DSL.hpp"

BOOST_AUTO_TEST_CASE(regex_prepare_int) {
	std::string to_prepare = "(parameter $i)";
	std::string prepared = Olamani::DSL::prepareRegex(to_prepare);
	BOOST_CHECK_EQUAL("\\(parameter\\s+(\\d+)\\)", prepared);
}

BOOST_AUTO_TEST_CASE(regex_prepare_double) {
	std::string to_prepare = "(parameter $d)";
	std::string prepared = Olamani::DSL::prepareRegex(to_prepare);
	BOOST_CHECK_EQUAL("\\(parameter\\s+([\\d\\.\\-e]+)\\)", prepared);
}

BOOST_AUTO_TEST_CASE(regex_prepare_string) {
	std::string to_prepare = "(parameter $s)";
	std::string prepared = Olamani::DSL::prepareRegex(to_prepare);
	BOOST_CHECK_EQUAL("\\(parameter\\s+(\\w+)\\)", prepared);
}

BOOST_AUTO_TEST_CASE(regex_prepare_double_int_string) {
	std::string to_prepare = "(parameter $d (parameter $i)$_(parameter $s))";
	std::string prepared = Olamani::DSL::prepareRegex(to_prepare);
	BOOST_CHECK_EQUAL("\\(parameter\\s+([\\d\\.\\-e]+)\\s+\\(parameter\\s+(\\d+)\\)\\s*\\(parameter\\s+(\\w+)\\)\\)", prepared);
}

BOOST_AUTO_TEST_CASE(regex_prepare_regexes_target) {
	std::string to_prepare = "(parameter $(t))";
	std::string prepared = Olamani::DSL::prepareRegex(to_prepare);
	BOOST_CHECK_EQUAL("\\(parameter\\s+(none|[lr]\\s+\\d+)\\)", prepared);
}

BOOST_AUTO_TEST_CASE(regex_prepare_regexes_collisions) {
	std::string to_prepare = "(parameter $(l))";
	std::string prepared = Olamani::DSL::prepareRegex(to_prepare);
	BOOST_CHECK_EQUAL("\\(parameter\\s+(none|\\(ball\\)|\\(player\\)|\\(post\\)|\\s)+\\)", prepared);
}

BOOST_AUTO_TEST_CASE(regex_prepare_regexes_card) {
	std::string to_prepare = "(parameter $(c))";
	std::string prepared = Olamani::DSL::prepareRegex(to_prepare);
	BOOST_CHECK_EQUAL("\\(parameter\\s+(none|yellow|red)\\)", prepared);
}

BOOST_AUTO_TEST_CASE(get_int_parameter) {
	std::string message = "(message (parameter 1))";
	int found = Olamani::DSL::getIntParameter(message, "parameter", 0);
	BOOST_CHECK_EQUAL(1, found);
}

BOOST_AUTO_TEST_CASE(get_int_parameter_default) {
	std::string message = "(message (other 1))";
	int found = Olamani::DSL::getIntParameter(message, "parameter", 0);
	BOOST_CHECK_EQUAL(0, found);
}

BOOST_AUTO_TEST_CASE(get_double_parameter) {
	std::string message = "(message (parameter 10)(other 2))";
	double found = Olamani::DSL::getDoubleParameter(message, "parameter", 0.0);
	BOOST_CHECK_CLOSE(10.0, found, 0.01);
}

BOOST_AUTO_TEST_CASE(get_double_parameter_default) {
	std::string message = "(message (other 1))";
	double found = Olamani::DSL::getDoubleParameter(message, "parameter", 0.0);
	BOOST_CHECK_CLOSE(0.0, found, 0.01);
}

BOOST_AUTO_TEST_CASE(get_string_parameter) {
	std::string message = "(message (parameter string))";
	std::string found = Olamani::DSL::getStringParameter(message, "parameter", "default");
	BOOST_CHECK_EQUAL(found, "string");
}

BOOST_AUTO_TEST_CASE(get_string_parameter_default) {
	std::string message = "(message (other string))";
	std::string found = Olamani::DSL::getStringParameter(message, "parameter", "default");
	BOOST_CHECK_EQUAL(found, "default");
}