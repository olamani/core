#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Server.hpp"

const double TOLERANCE = 0.01;

std::string server_params = "(server_param "
	"(audio_cut_dist 50)"
	"(auto_mode 0)"
	"(back_dash_rate 0.6)"
	"(back_passes 1)"
	"(ball_accel_max 2.7)"
	"(ball_decay 0.94)"
	"(ball_rand 0.05)"
	"(ball_size 0.085)"
	"(ball_speed_max 3)"
	"(ball_stuck_area 3)"
	"(ball_weight 0.2)"
	"(catch_ban_cycle 5)"
	"(catch_probability 1)"
	"(catchable_area_l 1.2)"
	"(catchable_area_w 1)"
	"(ckick_margin 1)"
	"(clang_advice_win 1)"
	"(clang_define_win 1)"
	"(clang_del_win 1)"
	"(clang_info_win 1)"
	"(clang_mess_delay 50)"
	"(clang_mess_per_cycle 1)"
	"(clang_meta_win 1)"
	"(clang_rule_win 1)"
	"(clang_win_size 300)"
	"(coach 0)"
	"(coach_port 6001)"
	"(coach_w_referee 0)"
	"(connect_wait 300)"
	"(control_radius 2)"
	"(dash_angle_step 45)"
	"(dash_power_rate 0.006)"
	"(drop_ball_time 100)"
	"(effort_dec 0.005)"
	"(effort_dec_thr 0.3)"
	"(effort_inc 0.01)"
	"(effort_inc_thr 0.6)"
	"(effort_init 1)"
	"(effort_min 0.6)"
	"(extra_half_time 100)"
	"(extra_stamina 50)"
	"(forbid_kick_off_offside 1)"
	"(foul_cycles 5)"
	"(foul_detect_probability 0.5)"
	"(foul_exponent 10)"
	"(free_kick_faults 1)"
	"(freeform_send_period 20)"
	"(freeform_wait_period 600)"
	"(fullstate_l 0)"
	"(fullstate_r 0)"
	"(game_log_compression 0)"
	"(game_log_dated 1)"
	"(game_log_dir \"./\")"
	"(game_log_fixed 0)"
	"(game_log_fixed_name \"rcssserver\")"
	"(game_log_version 5)"
	"(game_logging 1)"
	"(game_over_wait 100)"
	"(goal_width 14.02)"
	"(goalie_max_moves 2)"
	"(golden_goal 0)"
	"(half_time 300)"
	"(hear_decay 1)"
	"(hear_inc 1)"
	"(hear_max 1)"
	"(inertia_moment 5)"
	"(keepaway 0)"
	"(keepaway_length 20)"
	"(keepaway_log_dated 1)"
	"(keepaway_log_dir \"./\")"
	"(keepaway_log_fixed 0)"
	"(keepaway_log_fixed_name \"rcssserver\")"
	"(keepaway_logging 1)"
	"(keepaway_start -1)"
	"(keepaway_width 20)"
	"(kick_off_wait 100)"
	"(kick_power_rate 0.027)"
	"(kick_rand 0.1)"
	"(kick_rand_factor_l 1)"
	"(kick_rand_factor_r 1)"
	"(kickable_margin 0.7)"
	"(landmark_file \"~/.rcssserver-landmark.xml\")"
	"(log_date_format \"%Y%m%d%H%M%S-\")"
	"(log_times 0)"
	"(max_back_tackle_power 0)"
	"(max_dash_angle 180)"
	"(max_dash_power 100)"
	"(max_goal_kicks 3)"
	"(max_tackle_power 100)"
	"(maxmoment 180)"
	"(maxneckang 90)"
	"(maxneckmoment 180)"
	"(maxpower 100)"
	"(min_dash_angle -180)"
	"(min_dash_power -100)"
	"(minmoment -180)"
	"(minneckang -90)"
	"(minneckmoment -180)"
	"(minpower -100)"
	"(nr_extra_halfs 2)"
	"(nr_normal_halfs 2)"
	"(offside_active_area_size 2.5)"
	"(offside_kick_margin 9.15)"
	"(olcoach_port 6002)"
	"(old_coach_hear 0)"
	"(pen_allow_mult_kicks 1)"
	"(pen_before_setup_wait 10)"
	"(pen_coach_moves_players 1)"
	"(pen_dist_x 42.5)"
	"(pen_max_extra_kicks 5)"
	"(pen_max_goalie_dist_x 14)"
	"(pen_nr_kicks 5)"
	"(pen_random_winner 0)"
	"(pen_ready_wait 10)"
	"(pen_setup_wait 70)"
	"(pen_taken_wait 150)"
	"(penalty_shoot_outs 1)"
	"(player_accel_max 1)"
	"(player_decay 0.4)"
	"(player_rand 0.1)"
	"(player_size 0.3)"
	"(player_speed_max 1.05)"
	"(player_speed_max_min 0.75)"
	"(player_weight 60)"
	"(point_to_ban 5)"
	"(point_to_duration 20)"
	"(port 6000)"
	"(prand_factor_l 1)"
	"(prand_factor_r 1)"
	"(profile 0)"
	"(proper_goal_kicks 0)"
	"(quantize_step 0.1)"
	"(quantize_step_l 0.01)"
	"(record_messages 0)"
	"(recover_dec 0.002)"
	"(recover_dec_thr 0.3)"
	"(recover_init 1)"
	"(recover_min 0.5)"
	"(recv_step 10)"
	"(red_card_probability 0)"
	"(say_coach_cnt_max 128)"
	"(say_coach_msg_size 128)"
	"(say_msg_size 10)"
	"(send_comms 0)"
	"(send_step 150)"
	"(send_vi_step 100)"
	"(sense_body_step 100)"
	"(side_dash_rate 0.4)"
	"(simulator_step 100)"
	"(slow_down_factor 1)"
	"(slowness_on_top_for_left_team 1)"
	"(slowness_on_top_for_right_team 1)"
	"(stamina_capacity 130600)"
	"(stamina_inc_max 45)"
	"(stamina_max 8000)"
	"(start_goal_l 0)"
	"(start_goal_r 0)"
	"(stopped_ball_vel 0.01)"
	"(synch_micro_sleep 1)"
	"(synch_mode 0)"
	"(synch_offset 60)"
	"(synch_see_offset 0)"
	"(tackle_back_dist 0)"
	"(tackle_cycles 10)"
	"(tackle_dist 2)"
	"(tackle_exponent 6)"
	"(tackle_power_rate 0.027)"
	"(tackle_rand_factor 2)"
	"(tackle_width 1.25)"
	"(team_actuator_noise 0)"
	"(team_l_start \"\")"
	"(team_r_start \"\")"
	"(text_log_compression 0)"
	"(text_log_dated 1)"
	"(text_log_dir \"./\")"
	"(text_log_fixed 0)"
	"(text_log_fixed_name \"rcssserver\")"
	"(text_logging 1)"
	"(use_offside 1)"
	"(verbose 0)"
	"(visible_angle 90)"
	"(visible_distance 3)"
	"(wind_ang 0)"
	"(wind_dir 0)"
	"(wind_force 0)"
	"(wind_none 0)"
	"(wind_rand 0)"
	"(wind_random 0))";

BOOST_AUTO_TEST_CASE(parse_server_params) {
	Olamani::Server::handleServerParameters(server_params);
	BOOST_CHECK_CLOSE(50.0, Olamani::Server::AUDIO_CUT_DIST, TOLERANCE);
	BOOST_CHECK_EQUAL(false, Olamani::Server::AUTO_MODE);
	BOOST_CHECK_CLOSE(0.6, Olamani::Server::BACK_DASH_RATE, TOLERANCE);
	BOOST_CHECK_EQUAL(1, Olamani::Server::BACK_PASSES);
	BOOST_CHECK_CLOSE(2.7, Olamani::Server::BALL_ACCEL_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.94, Olamani::Server::BALL_DECAY, TOLERANCE);
	BOOST_CHECK_CLOSE(0.05, Olamani::Server::BALL_RAND, TOLERANCE);
	BOOST_CHECK_CLOSE(0.085, Olamani::Server::BALL_SIZE, TOLERANCE);
	BOOST_CHECK_CLOSE(3.0, Olamani::Server::BALL_SPEED_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(3.0, Olamani::Server::BALL_STUCK_AREA, TOLERANCE);
	BOOST_CHECK_CLOSE(0.2, Olamani::Server::BALL_WEIGHT, TOLERANCE);
	BOOST_CHECK_EQUAL(5, Olamani::Server::CATCH_BAN_CYCLE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::CATCH_PROBABILITY, TOLERANCE);
	BOOST_CHECK_CLOSE(1.2, Olamani::Server::CATCHABLE_AREA_L, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::CATCHABLE_AREA_W, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::CKICK_MARGIN, TOLERANCE);
	BOOST_CHECK_EQUAL(1, Olamani::Server::CLANG_ADVICE_WIN);
	BOOST_CHECK_EQUAL(1, Olamani::Server::CLANG_DEFINE_WIN);
	BOOST_CHECK_EQUAL(1, Olamani::Server::CLANG_DEL_WIN);
	BOOST_CHECK_EQUAL(1, Olamani::Server::CLANG_INFO_WIN);
	BOOST_CHECK_EQUAL(50, Olamani::Server::CLANG_MESS_DELAY);
	BOOST_CHECK_EQUAL(1, Olamani::Server::CLANG_MESS_PER_CYCLE);
	BOOST_CHECK_EQUAL(1, Olamani::Server::CLANG_META_WIN);
	BOOST_CHECK_EQUAL(1, Olamani::Server::CLANG_RULE_WIN);
	BOOST_CHECK_EQUAL(300, Olamani::Server::CLANG_WIN_SIZE);
	BOOST_CHECK_EQUAL(false, Olamani::Server::COACH);
	BOOST_CHECK_EQUAL(6001, Olamani::Server::COACH_PORT);
	BOOST_CHECK_EQUAL(false, Olamani::Server::COACH_W_REFEREE);
	BOOST_CHECK_EQUAL(300, Olamani::Server::CONNECT_WAIT);
	BOOST_CHECK_CLOSE(2.0, Olamani::Server::CONTROL_RADIUS, TOLERANCE);
	BOOST_CHECK_CLOSE(45, Olamani::Server::DASH_ANGLE_STEP, TOLERANCE);
	BOOST_CHECK_CLOSE(0.006, Olamani::Server::DASH_POWER_RATE, TOLERANCE);
	BOOST_CHECK_EQUAL(100, Olamani::Server::DROP_BALL_TIME);
	BOOST_CHECK_CLOSE(0.005, Olamani::Server::EFFORT_DEC, TOLERANCE);
	BOOST_CHECK_CLOSE(0.3, Olamani::Server::EFFORT_DEC_THR, TOLERANCE);
	BOOST_CHECK_CLOSE(0.01, Olamani::Server::EFFORT_INC, TOLERANCE);
	BOOST_CHECK_CLOSE(0.6, Olamani::Server::EFFORT_INC_THR, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::EFFORT_INIT, TOLERANCE);
	BOOST_CHECK_CLOSE(0.6, Olamani::Server::EFFORT_MIN, TOLERANCE);
	BOOST_CHECK_EQUAL(100, Olamani::Server::EXTRA_HALF_TIME);
	BOOST_CHECK_CLOSE(50.0, Olamani::Server::EXTRA_STAMINA, TOLERANCE);
	BOOST_CHECK_EQUAL(true, Olamani::Server::FORBID_KICK_OFF_OFFSIDE);
	BOOST_CHECK_EQUAL(5, Olamani::Server::FOUL_CYCLES);
	BOOST_CHECK_CLOSE(0.5, Olamani::Server::FOUL_DETECT_PROBABILITY, TOLERANCE);
	BOOST_CHECK_EQUAL(10, Olamani::Server::FOUL_EXPONENT);
	BOOST_CHECK_EQUAL(1, Olamani::Server::FREE_KICK_FAULTS);
	BOOST_CHECK_EQUAL(20, Olamani::Server::FREEFORM_SEND_PERIOD);
	BOOST_CHECK_EQUAL(600, Olamani::Server::FREEFORM_WAIT_PERIOD);
	BOOST_CHECK_EQUAL(false, Olamani::Server::FULLSTATE_L);
	BOOST_CHECK_EQUAL(false, Olamani::Server::FULLSTATE_R);
	BOOST_CHECK_EQUAL(0, Olamani::Server::GAME_LOG_COMPRESSION);
	BOOST_CHECK_EQUAL(1, Olamani::Server::GAME_LOG_DATED);
	BOOST_CHECK_EQUAL("./", Olamani::Server::GAME_LOG_DIR);
	BOOST_CHECK_EQUAL(0, Olamani::Server::GAME_LOG_FIXED);
	BOOST_CHECK_EQUAL("rcssserver", Olamani::Server::GAME_LOG_FIXED_NAME);
	BOOST_CHECK_EQUAL(5, Olamani::Server::GAME_LOG_VERSION);
	BOOST_CHECK_EQUAL(true, Olamani::Server::GAME_LOGGING);
	BOOST_CHECK_EQUAL(100, Olamani::Server::GAME_OVER_WAIT);
	BOOST_CHECK_CLOSE(14.02, Olamani::Server::GOAL_WIDTH, TOLERANCE);
	BOOST_CHECK_EQUAL(2, Olamani::Server::GOALIE_MAX_MOVES);
	BOOST_CHECK_EQUAL(false, Olamani::Server::GOLDEN_GOAL);
	BOOST_CHECK_EQUAL(300, Olamani::Server::HALF_TIME);
	BOOST_CHECK_EQUAL(1, Olamani::Server::HEAR_DECAY);
	BOOST_CHECK_EQUAL(1, Olamani::Server::HEAR_INC);
	BOOST_CHECK_EQUAL(1, Olamani::Server::HEAR_MAX);
	BOOST_CHECK_CLOSE(5.0, Olamani::Server::INERTIA_MOMENT, TOLERANCE);
	BOOST_CHECK_EQUAL(false, Olamani::Server::KEEPAWAY);
	BOOST_CHECK_EQUAL(20, Olamani::Server::KEEPAWAY_LENGTH);
	BOOST_CHECK_EQUAL(true, Olamani::Server::KEEPAWAY_LOG_DATED);
	BOOST_CHECK_EQUAL("./", Olamani::Server::KEEPAWAY_LOG_DIR);
	BOOST_CHECK_EQUAL(0, Olamani::Server::KEEPAWAY_LOG_FIXED);
	BOOST_CHECK_EQUAL("rcssserver", Olamani::Server::KEEPAWAY_LOG_FIXED_NAME);
	BOOST_CHECK_EQUAL(true, Olamani::Server::KEEPAWAY_LOGGING);
	BOOST_CHECK_EQUAL(-1, Olamani::Server::KEEPAWAY_START);
	BOOST_CHECK_EQUAL(20, Olamani::Server::KEEPAWAY_WIDTH);
	BOOST_CHECK_EQUAL(100, Olamani::Server::KICK_OFF_WAIT);
	BOOST_CHECK_CLOSE(0.027, Olamani::Server::KICK_POWER_RATE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.1, Olamani::Server::KICK_RAND, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::KICK_RAND_FACTOR_L, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::KICK_RAND_FACTOR_R, TOLERANCE);
	BOOST_CHECK_CLOSE(0.7, Olamani::Server::KICKABLE_MARGIN, TOLERANCE);
	BOOST_CHECK_EQUAL("~/.rcssserver-landmark.xml", Olamani::Server::LANDMARK_FILE);
	BOOST_CHECK_EQUAL("%Y%m%d%H%M%S-", Olamani::Server::LOG_DATE_FORMAT);
	BOOST_CHECK_EQUAL(false, Olamani::Server::LOG_TIMES);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::MAX_BACK_TACKLE_POWER, TOLERANCE);
	BOOST_CHECK_CLOSE(180.0, Olamani::Server::MAX_DASH_ANGLE, TOLERANCE);
	BOOST_CHECK_CLOSE(100.0, Olamani::Server::MAX_DASH_POWER, TOLERANCE);
	BOOST_CHECK_EQUAL(3, Olamani::Server::MAX_GOAL_KICKS);
	BOOST_CHECK_CLOSE(100.0, Olamani::Server::MAX_TACKLE_POWER, TOLERANCE);
	BOOST_CHECK_CLOSE(180.0, Olamani::Server::MAXMOMENT, TOLERANCE);
	BOOST_CHECK_CLOSE(90.0, Olamani::Server::MAXNECKANG, TOLERANCE);
	BOOST_CHECK_CLOSE(180.0, Olamani::Server::MAXNECKMOMENT, TOLERANCE);
	BOOST_CHECK_CLOSE(100.0, Olamani::Server::MAXPOWER, TOLERANCE);
	BOOST_CHECK_CLOSE(-180.0, Olamani::Server::MIN_DASH_ANGLE, TOLERANCE);
	BOOST_CHECK_CLOSE(-100.0, Olamani::Server::MIN_DASH_POWER, TOLERANCE);
	BOOST_CHECK_CLOSE(-180.0, Olamani::Server::MINMOMENT, TOLERANCE);
	BOOST_CHECK_CLOSE(-90.0, Olamani::Server::MINNECKANG, TOLERANCE);
	BOOST_CHECK_CLOSE(-180.0, Olamani::Server::MINNECKMOMENT, TOLERANCE);
	BOOST_CHECK_CLOSE(-100.0, Olamani::Server::MINPOWER, TOLERANCE);
	BOOST_CHECK_EQUAL(2, Olamani::Server::NR_EXTRA_HALFS);
	BOOST_CHECK_EQUAL(2, Olamani::Server::NR_NORMAL_HALFS);
	BOOST_CHECK_CLOSE(2.5, Olamani::Server::OFFSIDE_ACTIVE_AREA_SIZE, TOLERANCE);
	BOOST_CHECK_CLOSE(9.15, Olamani::Server::OFFSIDE_KICK_MARGIN, TOLERANCE);
	BOOST_CHECK_EQUAL(6002, Olamani::Server::OLCOACH_PORT);
	BOOST_CHECK_EQUAL(0, Olamani::Server::OLD_COACH_HEAR);
	BOOST_CHECK_EQUAL(true, Olamani::Server::PEN_ALLOW_MULT_KICKS);
	BOOST_CHECK_EQUAL(10, Olamani::Server::PEN_BEFORE_SETUP_WAIT);
	BOOST_CHECK_EQUAL(1, Olamani::Server::PEN_COACH_MOVES_PLAYERS);
	BOOST_CHECK_CLOSE(42.5, Olamani::Server::PEN_DIST_X, TOLERANCE);
	BOOST_CHECK_EQUAL(5, Olamani::Server::PEN_MAX_EXTRA_KICKS);
	BOOST_CHECK_CLOSE(14.0, Olamani::Server::PEN_MAX_GOALIE_DIST_X, TOLERANCE);
	BOOST_CHECK_EQUAL(5, Olamani::Server::PEN_NR_KICKS);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::PEN_RANDOM_WINNER, TOLERANCE);
	BOOST_CHECK_EQUAL(10, Olamani::Server::PEN_READY_WAIT);
	BOOST_CHECK_EQUAL(70, Olamani::Server::PEN_SETUP_WAIT);
	BOOST_CHECK_EQUAL(150, Olamani::Server::PEN_TAKEN_WAIT);
	BOOST_CHECK_EQUAL(1, Olamani::Server::PENALTY_SHOOT_OUTS);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::PLAYER_ACCEL_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.4, Olamani::Server::PLAYER_DECAY, TOLERANCE);
	BOOST_CHECK_CLOSE(0.1, Olamani::Server::PLAYER_RAND, TOLERANCE);
	BOOST_CHECK_CLOSE(0.3, Olamani::Server::PLAYER_SIZE, TOLERANCE);
	BOOST_CHECK_CLOSE(1.05, Olamani::Server::PLAYER_SPEED_MAX, TOLERANCE);
	BOOST_CHECK_CLOSE(0.75, Olamani::Server::PLAYER_SPEED_MAX_MIN, TOLERANCE);
	BOOST_CHECK_CLOSE(60.0, Olamani::Server::PLAYER_WEIGHT, TOLERANCE);
	BOOST_CHECK_EQUAL(5, Olamani::Server::POINT_TO_BAN);
	BOOST_CHECK_EQUAL(20, Olamani::Server::POINT_TO_DURATION);
	BOOST_CHECK_EQUAL(6000, Olamani::Server::PORT);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::PRAND_FACTOR_L, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::PRAND_FACTOR_R, TOLERANCE);
	BOOST_CHECK_EQUAL(0, Olamani::Server::PROFILE);
	BOOST_CHECK_EQUAL(0, Olamani::Server::PROPER_GOAL_KICKS);
	BOOST_CHECK_CLOSE(0.1, Olamani::Server::QUANTIZE_STEP, TOLERANCE);
	BOOST_CHECK_CLOSE(0.01, Olamani::Server::QUANTIZE_STEP_L, TOLERANCE);
	BOOST_CHECK_EQUAL(0, Olamani::Server::RECORD_MESSAGES);
	BOOST_CHECK_CLOSE(0.002, Olamani::Server::RECOVER_DEC, TOLERANCE);
	BOOST_CHECK_CLOSE(0.3, Olamani::Server::RECOVER_DEC_THR, TOLERANCE);
	BOOST_CHECK_EQUAL(1.0, Olamani::Server::RECOVER_INIT);
	BOOST_CHECK_CLOSE(0.5, Olamani::Server::RECOVER_MIN, TOLERANCE);
	BOOST_CHECK_EQUAL(10, Olamani::Server::RECV_STEP);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::RED_CARD_PROBABILITY, TOLERANCE);
	BOOST_CHECK_EQUAL(128, Olamani::Server::SAY_COACH_CNT_MAX);
	BOOST_CHECK_EQUAL(128, Olamani::Server::SAY_COACH_MSG_SIZE);
	BOOST_CHECK_EQUAL(10, Olamani::Server::SAY_MSG_SIZE);
	BOOST_CHECK_EQUAL(0, Olamani::Server::SEND_COMMS);
	BOOST_CHECK_EQUAL(150, Olamani::Server::SEND_STEP);
	BOOST_CHECK_EQUAL(100, Olamani::Server::SEND_VI_STEP);
	BOOST_CHECK_EQUAL(100, Olamani::Server::SENSE_BODY_STEP);
	BOOST_CHECK_CLOSE(0.4, Olamani::Server::SIDE_DASH_RATE, TOLERANCE);
	BOOST_CHECK_EQUAL(100, Olamani::Server::SIMULATOR_STEP);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::SLOW_DOWN_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::SLOWNESS_ON_TOP_FOR_LEFT_TEAM, TOLERANCE);
	BOOST_CHECK_CLOSE(1.0, Olamani::Server::SLOWNESS_ON_TOP_FOR_RIGHT_TEAM, TOLERANCE);
	BOOST_CHECK_EQUAL(130600, Olamani::Server::STAMINA_CAPACITY);
	BOOST_CHECK_EQUAL(45, Olamani::Server::STAMINA_INC_MAX);
	BOOST_CHECK_EQUAL(8000, Olamani::Server::STAMINA_MAX);
	BOOST_CHECK_EQUAL(0, Olamani::Server::START_GOAL_L);
	BOOST_CHECK_EQUAL(0, Olamani::Server::START_GOAL_R);
	BOOST_CHECK_CLOSE(0.01, Olamani::Server::STOPPED_BALL_VEL, TOLERANCE);
	BOOST_CHECK_EQUAL(1, Olamani::Server::SYNCH_MICRO_SLEEP);
	BOOST_CHECK_EQUAL(false, Olamani::Server::SYNCH_MODE);
	BOOST_CHECK_EQUAL(60, Olamani::Server::SYNCH_OFFSET);
	BOOST_CHECK_EQUAL(0, Olamani::Server::SYNCH_SEE_OFFSET);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::TACKLE_BACK_DIST, TOLERANCE);
	BOOST_CHECK_EQUAL(10, Olamani::Server::TACKLE_CYCLES);
	BOOST_CHECK_CLOSE(2.0, Olamani::Server::TACKLE_DIST, TOLERANCE);
	BOOST_CHECK_EQUAL(6, Olamani::Server::TACKLE_EXPONENT);
	BOOST_CHECK_CLOSE(0.027, Olamani::Server::TACKLE_POWER_RATE, TOLERANCE);
	BOOST_CHECK_CLOSE(2.0, Olamani::Server::TACKLE_RAND_FACTOR, TOLERANCE);
	BOOST_CHECK_CLOSE(1.25, Olamani::Server::TACKLE_WIDTH, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::TEAM_ACTUATOR_NOISE, TOLERANCE);
	BOOST_CHECK_EQUAL("", Olamani::Server::TEAM_L_START);
	BOOST_CHECK_EQUAL("", Olamani::Server::TEAM_R_START);
	BOOST_CHECK_EQUAL(false, Olamani::Server::TEXT_LOG_COMPRESSION);
	BOOST_CHECK_EQUAL(true, Olamani::Server::TEXT_LOG_DATED);
	BOOST_CHECK_EQUAL("./", Olamani::Server::TEXT_LOG_DIR);
	BOOST_CHECK_EQUAL(0, Olamani::Server::TEXT_LOG_FIXED);
	BOOST_CHECK_EQUAL("rcssserver", Olamani::Server::TEXT_LOG_FIXED_NAME);
	BOOST_CHECK_EQUAL(true, Olamani::Server::TEXT_LOGGING);
	BOOST_CHECK_EQUAL(true, Olamani::Server::USE_OFFSIDE);
	BOOST_CHECK_EQUAL(false, Olamani::Server::VERBOSE);
	BOOST_CHECK_CLOSE(90.0, Olamani::Server::VISIBLE_ANGLE, TOLERANCE);
	BOOST_CHECK_CLOSE(3.0, Olamani::Server::VISIBLE_DISTANCE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::WIND_ANG, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::WIND_DIR, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::WIND_FORCE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::WIND_NONE, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::WIND_RAND, TOLERANCE);
	BOOST_CHECK_CLOSE(0.0, Olamani::Server::WIND_RANDOM, TOLERANCE);
}