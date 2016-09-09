#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Body.hpp"

const double TOLERANCE = 0.01;

std::string player_params = "(player_param "
	"(allow_mult_default_type 0)"
	"(catchable_area_l_stretch_max 1.3)"
	"(catchable_area_l_stretch_min 1)"
	"(dash_power_rate_delta_max 0)"
	"(dash_power_rate_delta_min 0)"
	"(effort_max_delta_factor -0.004)"
	"(effort_min_delta_factor -0.004)"
	"(extra_stamina_delta_max 50)"
	"(extra_stamina_delta_min 0)"
	"(foul_detect_probability_delta_factor 0)"
	"(inertia_moment_delta_factor 25)"
	"(kick_power_rate_delta_max 0)"
	"(kick_power_rate_delta_min 0)"
	"(kick_rand_delta_factor 1)"
	"(kickable_margin_delta_max 0.1)"
	"(kickable_margin_delta_min -0.1)"
	"(new_dash_power_rate_delta_max 0.0008)"
	"(new_dash_power_rate_delta_min -0.0012)"
	"(new_stamina_inc_max_delta_factor -6000)"
	"(player_decay_delta_max 0.1)"
	"(player_decay_delta_min -0.1)"
	"(player_size_delta_factor -100)"
	"(player_speed_max_delta_max 0)"
	"(player_speed_max_delta_min 0)"
	"(player_types 18)"
	"(pt_max 1)"
	"(random_seed 1470779777)"
	"(stamina_inc_max_delta_factor 0)"
	"(subs_max 3))";
std::string player_type_0 = "(player_type "
	"(id 0)"
	"(player_speed_max 1.05)"
	"(stamina_inc_max 45)"
	"(player_decay 0.4)"
	"(inertia_moment 5)"
	"(dash_power_rate 0.006)"
	"(player_size 0.3)"
	"(kickable_margin 0.7)"
	"(kick_rand 0.1)"
	"(extra_stamina 50)"
	"(effort_max 1)"
	"(effort_min 0.6)"
	"(kick_power_rate 0.027)"
	"(foul_detect_probability 0.5)"
	"(catchable_area_l_stretch 1))";
std::string player_type_1 = "(player_type "
	"(id 1)"
	"(player_speed_max 1.05)"
	"(stamina_inc_max 48.5617)"
	"(player_decay 0.365355)"
	"(inertia_moment 4.13389)"
	"(dash_power_rate 0.00540638)"
	"(player_size 0.3)"
	"(kickable_margin 0.666867)"
	"(kick_rand 0.0668668)"
	"(extra_stamina 60.371)"
	"(effort_max 0.958516)"
	"(effort_min 0.558516)"
	"(kick_power_rate 0.027)"
	"(foul_detect_probability 0.5)"
	"(catchable_area_l_stretch 1.1488))";
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
std::string sense_body_1 = "(sense_body 11 "
	"(view_mode low wide) "
	"(stamina 7000 2 130000) "
	"(speed 1.0 7) "
	"(head_angle 20) "
	"(kick 2) "
	"(dash 3) "
	"(turn 4) "
	"(say 5) "
	"(turn_neck 6) "
	"(catch 7) "
	"(move 8) "
	"(change_view 9) "
	"(arm (movable 1) "
		"(expires 3) "
		"(target 5 6) "
		"(count 10)) "
	"(focus (target none) "
		"(count 11)) "
	"(tackle (expires 4) "
		"(count 12)) "
	"(collision none) "
	"(foul  (charged 0) "
		"(card none)))";

BOOST_AUTO_TEST_CASE(parse_player_params) {
	Olamani::Body::handleParametersMessage(player_params);
	BOOST_CHECK_EQUAL(false, Olamani::Body::ALLOW_MULT_DEFAULT_TYPE);
	BOOST_CHECK_CLOSE(1.3, Olamani::Body::CATCHABLE_AREA_L_STRETCH_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::CATCHABLE_AREA_L_STRETCH_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Body::DASH_POWER_RATE_DELTA_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Body::DASH_POWER_RATE_DELTA_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(-0.004, Olamani::Body::EFFORT_MAX_DELTA_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(-0.004, Olamani::Body::EFFORT_MIN_DELTA_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(50.0, Olamani::Body::EXTRA_STAMINA_DELTA_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Body::EXTRA_STAMINA_DELTA_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Body::FOUL_DETECT_PROBABILITY_DELTA_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(25.0, Olamani::Body::INERTIA_MOMENT_DELTA_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Body::KICK_POWER_RATE_DELTA_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Body::KICK_POWER_RATE_DELTA_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::KICK_RAND_DELTA_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(0.1, Olamani::Body::KICKABLE_MARGIN_DELTA_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(-0.1, Olamani::Body::KICKABLE_MARGIN_DELTA_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0008, Olamani::Body::NEW_DASH_POWER_RATE_DELTA_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(-0.0012, Olamani::Body::NEW_DASH_POWER_RATE_DELTA_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(-6000.0, Olamani::Body::NEW_STAMINA_INC_MAX_DELTA_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(0.1, Olamani::Body::PLAYER_DECAY_DELTA_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(-0.1, Olamani::Body::PLAYER_DECAY_DELTA_MIN, TOLERANCE);
	BOOST_CHECK_EQUAL(18, Olamani::Body::PLAYER_TYPES);
	BOOST_CHECK_EQUAL(1, Olamani::Body::PT_MAX);
	BOOST_CHECK_EQUAL(1470779777, Olamani::Body::RANDOM_SEED);
	BOOST_CHECK_CLOSE(0.0, Olamani::Body::STAMINA_INC_MAX_DELTA_FACTOR, TOLERANCE);
	BOOST_CHECK_EQUAL(3, Olamani::Body::SUBS_MAX);
}

BOOST_AUTO_TEST_CASE(change_player_type) {
	Olamani::Body::clearTypes();
	Olamani::Body::handlePlayerTypeMessage(player_type_0);
	Olamani::Body::handlePlayerTypeMessage(player_type_1);
	Olamani::Body::changePlayerType(0);
	BOOST_CHECK_CLOSE(1.05, Olamani::Body::PLAYER_SPEED_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(45.0, Olamani::Body::STAMINA_INC_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.4, Olamani::Body::PLAYER_DECAY, TOLERANCE);
	BOOST_CHECK_CLOSE(5.0, Olamani::Body::INERTIA_MOMENT, TOLERANCE);
	BOOST_CHECK_CLOSE(0.006, Olamani::Body::DASH_POWER_RATE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.3, Olamani::Body::PLAYER_SIZE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.7, Olamani::Body::KICKABLE_MARGIN, TOLERANCE);
	BOOST_CHECK_CLOSE(0.1, Olamani::Body::KICK_RAND, TOLERANCE);
	BOOST_CHECK_CLOSE(50.0, Olamani::Body::EXTRA_STAMINA, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::EFFORT_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.6, Olamani::Body::EFFORT_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(0.027, Olamani::Body::KICK_POWER_RATE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.5, Olamani::Body::FOUL_DETECT_PROBABILITY, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::CATCHABLE_AREA_L_STRETCH, TOLERANCE);
	Olamani::Body::changePlayerType(1);
	BOOST_CHECK_CLOSE(1.05, Olamani::Body::PLAYER_SPEED_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(48.5617, Olamani::Body::STAMINA_INC_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.365355, Olamani::Body::PLAYER_DECAY, TOLERANCE);
	BOOST_CHECK_CLOSE(4.13389, Olamani::Body::INERTIA_MOMENT, TOLERANCE);
	BOOST_CHECK_CLOSE(0.00540638, Olamani::Body::DASH_POWER_RATE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.3, Olamani::Body::PLAYER_SIZE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.666867, Olamani::Body::KICKABLE_MARGIN, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0668668, Olamani::Body::KICK_RAND, TOLERANCE);
	BOOST_CHECK_CLOSE(60.371, Olamani::Body::EXTRA_STAMINA, TOLERANCE);
	BOOST_CHECK_CLOSE(0.958516, Olamani::Body::EFFORT_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.558516, Olamani::Body::EFFORT_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(0.027, Olamani::Body::KICK_POWER_RATE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.5, Olamani::Body::FOUL_DETECT_PROBABILITY, TOLERANCE);
	BOOST_CHECK_CLOSE(1.1488, Olamani::Body::CATCHABLE_AREA_L_STRETCH, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(handle_sense_body) {
	Olamani::Body::handleBodyMessage(sense_body_0);
	BOOST_CHECK_CLOSE(1.5, Olamani::Body::AMOUNT_OF_SPEED, TOLERANCE);
	BOOST_CHECK_CLOSE(1.5, Olamani::Body::amountOfSpeed(), TOLERANCE);
	BOOST_CHECK_EQUAL(9, Olamani::Body::ARM_COUNT);
	BOOST_CHECK_EQUAL(9, Olamani::Body::armCount());
	BOOST_CHECK_CLOSE(12.0, Olamani::Body::ARM_DIRECTION, TOLERANCE);
	BOOST_CHECK_CLOSE(12.0, Olamani::Body::armDirection(), TOLERANCE);
	BOOST_CHECK_CLOSE(10.0, Olamani::Body::ARM_DISTANCE, TOLERANCE);
	BOOST_CHECK_CLOSE(10.0, Olamani::Body::armDistance(), TOLERANCE);
	BOOST_CHECK_EQUAL(5, Olamani::Body::ARM_EXPIRES);
	BOOST_CHECK_EQUAL(5, Olamani::Body::armExpires());
	BOOST_CHECK_EQUAL(0, Olamani::Body::ARM_MOVABLE);
	BOOST_CHECK_EQUAL(0, Olamani::Body::armMovable());
	BOOST_CHECK_EQUAL(6, Olamani::Body::CATCH_COUNT);
	BOOST_CHECK_EQUAL(6, Olamani::Body::catchCount());
	// TODO: check collisions
	BOOST_CHECK_EQUAL(8, Olamani::Body::CHANGE_VIEW_COUNT);
	BOOST_CHECK_EQUAL(8, Olamani::Body::changeViewCount());
	BOOST_CHECK_EQUAL(2, Olamani::Body::DASH_COUNT);
	BOOST_CHECK_EQUAL(2, Olamani::Body::dashCount());
	BOOST_CHECK_CLOSE(5.0, Olamani::Body::DIRECTION_OF_SPEED, TOLERANCE);
	BOOST_CHECK_CLOSE(5.0, Olamani::Body::directionOfSpeed(), TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::EFFORT, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::effort(), TOLERANCE);
	BOOST_CHECK_EQUAL(10, Olamani::Body::FOCUS_COUNT);
	BOOST_CHECK_EQUAL(10, Olamani::Body::focusCount());
	BOOST_CHECK_EQUAL("none", Olamani::Body::FOCUS_TARGET);
	BOOST_CHECK_EQUAL("none", Olamani::Body::focusTarget());
	BOOST_CHECK_EQUAL("none", Olamani::Body::FOUL_CARD);
	BOOST_CHECK_EQUAL("none", Olamani::Body::foulCard());
	BOOST_CHECK_EQUAL(1, Olamani::Body::FOUL_CHARGED);
	BOOST_CHECK_EQUAL(1, Olamani::Body::foulCharged());
	BOOST_CHECK_CLOSE(45.0, Olamani::Body::HEAD_ANGLE, TOLERANCE);
	BOOST_CHECK_CLOSE(45.0, Olamani::Body::headAngle(), TOLERANCE);
	BOOST_CHECK_EQUAL(1, Olamani::Body::KICK_COUNT);
	BOOST_CHECK_EQUAL(1, Olamani::Body::kickCount());
	BOOST_CHECK_EQUAL(7, Olamani::Body::MOVE_COUNT);
	BOOST_CHECK_EQUAL(7, Olamani::Body::moveCount());
	BOOST_CHECK_EQUAL(4, Olamani::Body::SAY_COUNT);
	BOOST_CHECK_EQUAL(4, Olamani::Body::sayCount());
	BOOST_CHECK_CLOSE(8000.0, Olamani::Body::STAMINA, TOLERANCE);
	BOOST_CHECK_CLOSE(8000.0, Olamani::Body::stamina(), TOLERANCE);
	BOOST_CHECK_CLOSE(130600.0, Olamani::Body::STAMINA_CAPACITY, TOLERANCE);
	BOOST_CHECK_CLOSE(130600.0, Olamani::Body::staminaCapacity(), TOLERANCE);
	BOOST_CHECK_EQUAL(11, Olamani::Body::TACKLE_COUNT);
	BOOST_CHECK_EQUAL(11, Olamani::Body::tackleCount());
	BOOST_CHECK_EQUAL(7, Olamani::Body::TACKLE_EXPIRES);
	BOOST_CHECK_EQUAL(7, Olamani::Body::tackleExpires());
	BOOST_CHECK_EQUAL(3, Olamani::Body::TURN_COUNT);
	BOOST_CHECK_EQUAL(3, Olamani::Body::turnCount());
	BOOST_CHECK_EQUAL(5, Olamani::Body::TURN_NECK_COUNT);
	BOOST_CHECK_EQUAL(5, Olamani::Body::turnNeckCount());
	BOOST_CHECK_EQUAL("high", Olamani::Body::VIEW_MODE_QUALITY);
	BOOST_CHECK_EQUAL("high", Olamani::Body::viewModeQuality());
	BOOST_CHECK_EQUAL("normal", Olamani::Body::VIEW_MODE_WIDTH);
	BOOST_CHECK_EQUAL("normal", Olamani::Body::viewModeWidth());
}

BOOST_AUTO_TEST_CASE(sense_body_history) {
	Olamani::Body::handleBodyMessage(sense_body_0);
	Olamani::Body::handleBodyMessage(sense_body_1);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::AMOUNT_OF_SPEED, TOLERANCE);
	BOOST_CHECK_CLOSE(1.5, Olamani::Body::amountOfSpeed(1), TOLERANCE);
	BOOST_CHECK_EQUAL(10, Olamani::Body::ARM_COUNT);
	BOOST_CHECK_EQUAL(9, Olamani::Body::armCount(1));
	BOOST_CHECK_CLOSE(6.0, Olamani::Body::ARM_DIRECTION, TOLERANCE);
	BOOST_CHECK_CLOSE(12.0, Olamani::Body::armDirection(1), TOLERANCE);
	BOOST_CHECK_CLOSE(5.0, Olamani::Body::ARM_DISTANCE, TOLERANCE);
	BOOST_CHECK_CLOSE(10.0, Olamani::Body::armDistance(1), TOLERANCE);
	BOOST_CHECK_EQUAL(3, Olamani::Body::ARM_EXPIRES);
	BOOST_CHECK_EQUAL(5, Olamani::Body::armExpires(1));
	BOOST_CHECK_EQUAL(1, Olamani::Body::ARM_MOVABLE);
	BOOST_CHECK_EQUAL(0, Olamani::Body::armMovable(1));
	BOOST_CHECK_EQUAL(7, Olamani::Body::CATCH_COUNT);
	BOOST_CHECK_EQUAL(6, Olamani::Body::catchCount(1));
	// TODO: check collisions
	BOOST_CHECK_EQUAL(9, Olamani::Body::CHANGE_VIEW_COUNT);
	BOOST_CHECK_EQUAL(8, Olamani::Body::changeViewCount(1));
	BOOST_CHECK_EQUAL(3, Olamani::Body::DASH_COUNT);
	BOOST_CHECK_EQUAL(2, Olamani::Body::dashCount(1));
	BOOST_CHECK_CLOSE(7.0, Olamani::Body::DIRECTION_OF_SPEED, TOLERANCE);
	BOOST_CHECK_CLOSE(5.0, Olamani::Body::directionOfSpeed(1), TOLERANCE);
	BOOST_CHECK_CLOSE(2.0, Olamani::Body::EFFORT, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Body::effort(1), TOLERANCE);
	BOOST_CHECK_EQUAL(11, Olamani::Body::FOCUS_COUNT);
	BOOST_CHECK_EQUAL(10, Olamani::Body::focusCount(1));
	BOOST_CHECK_EQUAL("none", Olamani::Body::FOCUS_TARGET);
	BOOST_CHECK_EQUAL("none", Olamani::Body::focusTarget(1));
	BOOST_CHECK_EQUAL("none", Olamani::Body::FOUL_CARD);
	BOOST_CHECK_EQUAL("none", Olamani::Body::foulCard(1));
	BOOST_CHECK_EQUAL(0, Olamani::Body::FOUL_CHARGED);
	BOOST_CHECK_EQUAL(1, Olamani::Body::foulCharged(1));
	BOOST_CHECK_CLOSE(20.0, Olamani::Body::HEAD_ANGLE, TOLERANCE);
	BOOST_CHECK_CLOSE(45.0, Olamani::Body::headAngle(1), TOLERANCE);
	BOOST_CHECK_EQUAL(2, Olamani::Body::KICK_COUNT);
	BOOST_CHECK_EQUAL(1, Olamani::Body::kickCount(1));
	BOOST_CHECK_EQUAL(8, Olamani::Body::MOVE_COUNT);
	BOOST_CHECK_EQUAL(7, Olamani::Body::moveCount(1));
	BOOST_CHECK_EQUAL(5, Olamani::Body::SAY_COUNT);
	BOOST_CHECK_EQUAL(4, Olamani::Body::sayCount(1));
	BOOST_CHECK_CLOSE(7000.0, Olamani::Body::STAMINA, TOLERANCE);
	BOOST_CHECK_CLOSE(8000.0, Olamani::Body::stamina(1), TOLERANCE);
	BOOST_CHECK_CLOSE(130000.0, Olamani::Body::STAMINA_CAPACITY, TOLERANCE);
	BOOST_CHECK_CLOSE(130600.0, Olamani::Body::staminaCapacity(1), TOLERANCE);
	BOOST_CHECK_EQUAL(12, Olamani::Body::TACKLE_COUNT);
	BOOST_CHECK_EQUAL(11, Olamani::Body::tackleCount(1));
	BOOST_CHECK_EQUAL(4, Olamani::Body::TACKLE_EXPIRES);
	BOOST_CHECK_EQUAL(7, Olamani::Body::tackleExpires(1));
	BOOST_CHECK_EQUAL(4, Olamani::Body::TURN_COUNT);
	BOOST_CHECK_EQUAL(3, Olamani::Body::turnCount(1));
	BOOST_CHECK_EQUAL(6, Olamani::Body::TURN_NECK_COUNT);
	BOOST_CHECK_EQUAL(5, Olamani::Body::turnNeckCount(1));
	BOOST_CHECK_EQUAL("low", Olamani::Body::VIEW_MODE_QUALITY);
	BOOST_CHECK_EQUAL("high", Olamani::Body::viewModeQuality(1));
	BOOST_CHECK_EQUAL("wide", Olamani::Body::VIEW_MODE_WIDTH);
	BOOST_CHECK_EQUAL("normal", Olamani::Body::viewModeWidth(1));
}