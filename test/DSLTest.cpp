#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "DSL.hpp"

const double TOLERANCE = 0.01;

std::string sense_body_0 = "(sense_body 10 "
	"(view_mode high normal) "
	"(stamina 8000 1 130600) "
	"(speed 1.5 5) "
	"(head_angle 45) "
	"(kick 1) "
	"(dash 2) "
	"(turn 3) "
	"(say 4) "
	"(turn_neck 5) "
	"(catch 6) "
	"(move 7) "
	"(change_view 8) "
	"(arm (movable 0) "
		"(expires 5) "
		"(target 10 12) "
		"(count 9)) "
	"(focus (target none) "
		"(count 10)) "
	"(tackle (expires 7) "
		"(count 11)) "
	"(collision none) "
	"(foul  (charged 1) "
		"(card none)))";
std::string see_0 = "(see 0 "
	"((f r t) 55.7 3) "
	"((f g r b) 70.8 38) "
	"((g r) 66.7 34) "
	"((f g r t) 62.8 28) "
	"((f p r c) 53.5 43) "
	"((f p r t) 42.5 23) "
	"((f t 0) 3.6 -34 0 0) "
	"((f t r 10) 13.2 -9 0 0) "
	"((f t r 20) 23.1 -5 0 0) "
	"((f t r 30) 33.1 -3) "
	"((f t r 40) 42.9 -3) "
	"((f t r 50) 53 -2) "
	"((f r 0) 70.8 31) "
	"((f r t 10) 66 24) "
	"((f r t 20) 62.8 16) "
	"((f r t 30) 60.9 7) "
	"((f r b 10) 76.7 38) "
	"((f r b 20) 83.1 43))";

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

BOOST_AUTO_TEST_CASE(get_int_parameter_negative) {
	std::string message = "(message (parameter -1))";
	int found = Olamani::DSL::getIntParameter(message, "parameter", 0);
	BOOST_CHECK_EQUAL(-1, found);
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
	std::string message = "(message (parameter \"string\"))";
	std::string found = Olamani::DSL::getStringParameter(message, "parameter", "default");
	BOOST_CHECK_EQUAL(found, "string");
}

BOOST_AUTO_TEST_CASE(get_string_parameter_signs) {
	std::string message = "(message (parameter \".-/%~\"))";
	std::string found = Olamani::DSL::getStringParameter(message, "parameter", "default");
	BOOST_CHECK_EQUAL(found, ".-/%~");
}

BOOST_AUTO_TEST_CASE(get_string_parameter_default) {
	std::string message = "(message (other \"string\"))";
	std::string found = Olamani::DSL::getStringParameter(message, "parameter", "default");
	BOOST_CHECK_EQUAL(found, "default");
}

BOOST_AUTO_TEST_CASE(parse_sense_body) {
	Olamani::DSL::sense_body parsed = Olamani::DSL::parseSenseBody(sense_body_0);
	BOOST_CHECK_EQUAL(10, parsed.time);
	BOOST_CHECK_EQUAL("high", parsed.view_mode.quality);
	BOOST_CHECK_EQUAL("normal", parsed.view_mode.width);
	BOOST_CHECK_CLOSE(8000.0, parsed.stamina.stamina, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, parsed.stamina.effort, TOLERANCE);
	BOOST_CHECK_CLOSE(130600.0, parsed.stamina.capacity, TOLERANCE);
	BOOST_CHECK_CLOSE(1.5, parsed.speed.amount, TOLERANCE);
	BOOST_CHECK_CLOSE(5.0, parsed.speed.direction, TOLERANCE);
	BOOST_CHECK_CLOSE(45.0, parsed.head_angle, TOLERANCE);
	BOOST_CHECK_EQUAL(1, parsed.kick);
	BOOST_CHECK_EQUAL(2, parsed.dash);
	BOOST_CHECK_EQUAL(3, parsed.turn);
	BOOST_CHECK_EQUAL(4, parsed.say);
	BOOST_CHECK_EQUAL(5, parsed.turn_neck);
	BOOST_CHECK_EQUAL(6, parsed._catch);
	BOOST_CHECK_EQUAL(7, parsed.move);
	BOOST_CHECK_EQUAL(8, parsed.change_view);
	BOOST_CHECK_EQUAL(0, parsed.arm.movable);
	BOOST_CHECK_EQUAL(5, parsed.arm.expires);
	BOOST_CHECK_CLOSE(10.0, parsed.arm.distance, TOLERANCE);
	BOOST_CHECK_CLOSE(12.0, parsed.arm.direction, TOLERANCE);
	BOOST_CHECK_EQUAL(9, parsed.arm.count);
	BOOST_CHECK_EQUAL("none", parsed.focus.target);
	BOOST_CHECK_EQUAL(10, parsed.focus.count);
	BOOST_CHECK_EQUAL(7, parsed.tackle.expires);
	BOOST_CHECK_EQUAL(11, parsed.tackle.count);
	BOOST_CHECK_EQUAL("none", parsed.collision);
	BOOST_CHECK_EQUAL(1, parsed.foul.charged);
	BOOST_CHECK_EQUAL("none", parsed.foul.card);
}

BOOST_AUTO_TEST_CASE(parse_see) {
	Olamani::DSL::see parsed = Olamani::DSL::parseSee(see_0);
	BOOST_CHECK_EQUAL(18, parsed.objects.size());
	int flags = 0;
	int goals = 0;
	for (auto it = parsed.objects.begin(); it != parsed.objects.end(); ++it) {
		if (it->type == 'f') {
			flags++;
		} else if (it->type == 'g') {
			goals++;
		}
	}
	BOOST_CHECK_EQUAL(17, flags);
	BOOST_CHECK_EQUAL(1, goals);
}