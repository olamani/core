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
std::string sense_body_0 = "(sense_body 0 "
	"(view_mode high normal) "
	"(stamina 8000 1 130600) "
	"(speed 0 0) "
	"(head_angle 0) "
	"(kick 0) "
	"(dash 0) (turn 0) (say 0) (turn_neck 0) (catch 0) (move 0) (change_view 0) (arm (movable 0) (expires 0) (target 0 0) (count 0)) (focus (target none) (count 0)) (tackle (expires 0) (count 0)) (collision none) (foul  (charged 0) (card none)))";

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