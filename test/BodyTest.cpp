#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Body.hpp"

std::string player_params = "(player_param (allow_mult_default_type 0)(catchable_area_l_stretch_max 1.3)(catchable_area_l_stretch_min 1)(dash_power_rate_delta_max 0)(dash_power_rate_delta_min 0)(effort_max_delta_factor -0.004)(effort_min_delta_factor -0.004)(extra_stamina_delta_max 50)(extra_stamina_delta_min 0)(foul_detect_probability_delta_factor 0)(inertia_moment_delta_factor 25)(kick_power_rate_delta_max 0)(kick_power_rate_delta_min 0)(kick_rand_delta_factor 1)(kickable_margin_delta_max 0.1)(kickable_margin_delta_min -0.1)(new_dash_power_rate_delta_max 0.0008)(new_dash_power_rate_delta_min -0.0012)(new_stamina_inc_max_delta_factor -6000)(player_decay_delta_max 0.1)(player_decay_delta_min -0.1)(player_size_delta_factor -100)(player_speed_max_delta_max 0)(player_speed_max_delta_min 0)(player_types 18)(pt_max 1)(random_seed 1470779777)(stamina_inc_max_delta_factor 0)(subs_max 3))";
std::string sense_body = "(sense_body 0 (view_mode high normal) (stamina 8000 1 130600) (speed 0 0) (head_angle 0) (kick 0) (dash 0) (turn 0) (say 0) (turn_neck 0) (catch 0) (move 0) (change_view 0) (arm (movable 0) (expires 0) (target 0 0) (count 0)) (focus (target none) (count 0)) (tackle (expires 0) (count 0)) (collision none) (foul  (charged 0) (card none)))";
std::string player_type = "(player_type (id 0)(player_speed_max 1.05)(stamina_inc_max 45)(player_decay 0.4)(inertia_moment 5)(dash_power_rate 0.006)(player_size 0.3)(kickable_margin 0.7)(kick_rand 0.1)(extra_stamina 50)(effort_max 1)(effort_min 0.6)(kick_power_rate 0.027)(foul_detect_probability 0.5)(catchable_area_l_stretch 1))";