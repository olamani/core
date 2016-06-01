#include <string>
#include "DSL.hpp"

namespace Olamani {

namespace Server {

double      AUDIO_CUT_DIST = 0.0;
bool        AUTO_MODE = false;
double      BACK_DASH_RATE = 0.0;
int         BACK_PASSES = 0;
double      BALL_ACCEL_MAX = 0.0;
double      BALL_DECAY = 0.0;
double      BALL_RAND = 0.0;
double      BALL_SIZE = 0.0;
double      BALL_SPEED_MAX = 0.0;
double      BALL_STUCK_AREA = 0.0;
double      BALL_WEIGHT = 0.0;
int         CATCH_BAN_CYCLE = 0;
double      CATCHABLE_AREA_L = 0.0;
double      CATCHABLE_AREA_W = 0.0;
double      CKICK_MARGIN = 0.0;
int         CLANG_ADVICE_WIN = 0;
int         CLANG_DEFINE_WIN = 0;
int         CLANG_DEL_WIN = 0;
int         CLANG_INFO_WIN = 0;
int         CLANG_MESS_DELAY = 0;
int         CLANG_MESS_PER_CYCLE = 0;
int         CLANG_META_WIN = 0;
int         CLANG_RULE_WIN = 0;
int         CLANG_WIN_SIZE = 0;
bool        COACH = false;
int         COACH_PORT = 0;
bool        COACH_W_REFEREE = false;
int         CONNECT_WAIT = 0;
double      CONTROL_RADIUS = 0.0;
double      DASH_ANGLE_STEP = 0.0;
double      DASH_POWER_RATE = 0.0;
int         DROP_BALL_TIME = 0;
double      EFFORT_DEC = 0.0;
double      EFFORT_DEC_THR = 0.0;
double      EFFORT_INC = 0.0;
double      EFFORT_INC_THR = 0.0;
double      EFFORT_INIT = 0.0;
double      EFFORT_MIN = 0.0;
bool        EXTRA_HALF_TIME = 0;
int         EXTRA_STAMINA = 0;
int         FORBID_KICK_OFF_OFFSIDE = 0;
int         FOUL_CYCLES = 0;
double      FOUL_DETECT_PROBABILITY = 0.0;
int         FOUL_EXPONENT = 0;
int         FREE_KICK_FAULTS = 0;
int         FREEFORM_SEND_PERIOD = 0;
int         FREEFORM_WAIT_PERIOD = 0;
bool        FULLSTATE_L = false;
bool        FULLSTATE_R = false;
int         GAME_LOG_COMPRESSION = 0;
std::string GAME_LOG_DIR = "";
int         GAME_LOG_FIXED = 0;
std::string GAME_LOG_FIXED_NAME = "";
int         GAME_LOG_VERSION = 0;
bool        GAME_LOGGING = false;
int         GAME_OVER_WAIT = 0;
double      GOAL_WIDTH = 0.0;
int         GOALIE_MAX_MOVES = 0;
bool        GOLDEN_GOAL = false;
int         HALF_TIME = 0;
int         HEAR_DECAY = 0;
int         HEAR_INC = 0;
int         HEAR_MAX = 0;
double      INERTIA_MOMENT = 0.0;
bool        KEEPAWAY = false;
int         KEEPAWAY_LENGTH = 0;
bool        KEEPAWAY_LOG_DATED = false;
std::string KEEPAWAY_LOG_DIR = "";
int         KEEPAWAY_LOG_FIXED = 0;
std::string KEEPAWAY_LOG_FIXED_NAME = "";
bool        KEEPAWAY_LOGGING = false;
int         KEEPAWAY_START = 0;
int         KEEPAWAY_WIDTH = 0;
int         KICK_OFF_WAIT = 0;
double      KICK_POWER_RATE = 0.0;
double      KICK_RAND = 0.0;
double      KICK_RAND_FACTOR_L = 0.0;
double      KICK_RAND_FACTOR_R = 0.0;
double      KICKABLE_MARGIN = 0.0;
std::string LANDMARK_FILE = "";
std::string LOG_DATE_FORMAT = "";
bool        LOG_TIMES = false;
double      MAX_BACK_TACKLE_POWER = 0.0;
double      MAX_DASH_ANGLE = 0.0;
double      MAX_DASH_POWER = 0.0;
int         MAX_GOAL_KICKS = 0;
double      MAX_TACKLE_POWER = 0.0;
double      MAXMOMENT = 0.0;
double      MAXNECKANG = 0.0;
double      MAXNECKMOMENT = 0.0;
double      MAXPOWER = 0.0;
double      MIN_DASH_ANGLE = 0.0;
double      MIN_DASH_POWER = 0.0;
double      MINMOMENT = 0.0;
double      MINNECKANG = 0.0;
double      MINNECKMOMENT = 0.0;
double      MINPOWER = 0.0;
int         NR_EXTRA_HALFS = 0;
int         NR_NORMAL_HALFS = 0;
double      OFFSIDE_ACTIVE_AREA_SIZE = 0.0;
double      OFFSIDE_KICK_MARGIN = 0.0;
int         OLCOACH_PORT = 0;
int         OLD_COACH_HEAR = 0;
bool        PEN_ALLOW_MULT_KICKS = false;
int         PEN_BEFORE_SETUP_WAIT = 0;
int         PEN_COACH_MOVES_PLAYERS = 0;
double      PEN_DIST_X = 0.0;
int         PEN_MAX_EXTRA_KICKS = 0;
double      PEN_MAX_GOALIE_DIST_X = 0.0;
int         PEN_NR_KICKS = 0;
double      PEN_RANDOM_WINNER = 0.0;
int         PEN_READY_WAIT = 0;
int         PEN_SETUP_WAIT = 0;
int         PEN_TAKEN_WAIT = 0;
int         PENALTY_SHOOT_OUTS = 0;
double      PLAYER_ACCEL_MAX = 0.0;
double      PLAYER_DECAY = 0.0;
double      PLAYER_RAND = 0.0;
double      PLAYER_SIZE = 0.0;
double      PLAYER_SPEED_MAX = 0.0;
double      PLAYER_SPEED_MAX_MIN = 0.0;
double      PLAYER_WEIGHT = 0.0;
int         POINT_TO_BAN = 0;
int         POINT_TO_DURATION = 0;
int         PORT = 0;
int         PRAND_FACTOR_L = 0;
int         PRAND_FACTOR_R = 0;
int         PROFILE = 0;
int         PROPER_GOAL_KICKS = 0;
double      QUANTIZE_STEP = 0.0;
double      QUANTIZE_STEP_L = 0.0;
int         RECORD_MESSAGES = 0;
double      RECOVER_DEC = 0.0;
double      RECOVER_DEC_THR = 0.0;
double      RECOVER_INIT = 0.0;
double      RECOVER_MIN = 0.0;
int         RECV_STEP = 0;
double      RED_CARD_PROBABILITY = 0.0;
int         SAY_COACH_CNT_MAX = 0;
int         SAY_COACH_MSG_SIZE = 0;
int         SEND_COMMS = 0;
int         SEND_STEP = 0;
int         SEND_VI_STEP = 0;
int         SENSE_BODY_STEP = 0;
double      SIDE_DASH_RATE = 0.0;
int         SIMULATOR_STEP = 0;
double      SLOWNESS_ON_TOP_FOR_LEFT_TEAM = 0.0;
double      SLOWNESS_ON_TOP_FOR_RIGHT_TEAM = 0.0;
int         STAMINA_CAPACITY = 0;
int         STAMINA_INC_MAX = 0;
int         STAMINA_MAX = 0;
int         START_GOAL_L = 0;
int         START_GOAL_R = 0;
double      STOPPED_BALL_VEL = 0.0;
int         SYNCH_MICRO_SLEEP = 0;
bool        SYNCH_MODE = false;
int         SYNCH_OFFSET = 0;
int         SYNCH_SEE_OFFSET = 0;
double      TACKLE_BACK_DIST = 0.0;
int         TACKLE_CYCLES = 0;
double      TACKLE_DIST = 0.0;
int         TACKLE_EXPONENT = 0;
double      TACKLE_POWER_RATE = 0.0;
double      TACKLE_RAND_FACTOR = 0.0;
double      TACKLE_WIDTH = 0.0;
double      TEAM_ACTUATOR_NOISE = 0.0;
std::string TEAM_L_START = "";
std::string TEAM_R_START = "";
bool        TEXT_LOG_COMPRESSION = false;
bool        TEXT_LOG_DATED = false;
std::string TEXT_LOG_DIR = "";
int         TEXT_LOG_FIXED = 0;
std::string TEXT_LOG_FIXED_NAME = "";
bool        TEXT_LOGGING = false;
bool        USE_OFFSIDE = false;
bool        VERBOSE = false;
double      VISIBLE_ANGLE = 0.0;
double      VISIBLE_DISTANCE = 0.0;
double      WIND_ANG = 0.0;
double      WIND_DIR = 0.0;
double      WIND_FORCE = 0.0;
double      WIND_NONE = 0.0;
double      WIND_RAND = 0.0;
double      WIND_RANDOM = 0.0;

void handleServerParameters(std::string message) {
    AUDIO_CUT_DIST = getDoubleParameter(message, "audio_cut_dist", 0.0);
    AUTO_MODE = getBoolParameter(message, "auto_mode", false);
    BACK_DASH_RATE = getDoubleParameter(message, "back_dash_rate", 0.0);
    BACK_PASSES = getIntParameter(message, "back_passes", 0);
    BALL_ACCEL_MAX = getDoubleParameter(message, "ball_accel_max", 0.0);
    BALL_DECAY = getDoubleParameter(message, "ball_decay", 0.0);
    BALL_RAND = getDoubleParameter(message, "ball_rand", 0.0);
    BALL_SIZE = getDoubleParameter(message, "ball_size", 0.0);
    BALL_SPEED_MAX = getDoubleParameter(message, "ball_speed_max", 0.0);
    BALL_STUCK_AREA = getDoubleParameter(message, "ball_stuck_area", 0.0);
    BALL_WEIGHT = getDoubleParameter(message, "ball_weight", 0.0);
    CATCH_BAN_CYCLE = getIntParameter(message, "catch_ban_cycle", 0);
    CATCHABLE_AREA_L = getDoubleParameter(message, "catchable_area_l", 0.0);
    CATCHABLE_AREA_W = getDoubleParameter(message, "catchable_area_w", 0.0);
    CKICK_MARGIN = getDoubleParameter(message, "ckick_margin", 0.0);
    CLANG_ADVICE_WIN = getIntParameter(message, "clang_advice_win", 0);
    CLANG_DEFINE_WIN = getIntParameter(message, "clang_define_win", 0);
    CLANG_DEL_WIN = getIntParameter(message, "clang_del_win", 0);
    CLANG_INFO_WIN = getIntParameter(message, "clang_info_win", 0);
    CLANG_MESS_DELAY = getIntParameter(message, "clang_mess_delay", 0);
    CLANG_MESS_PER_CYCLE = getIntParameter(message, "clang_mess_per_cycle", 0);
    CLANG_META_WIN = getIntParameter(message, "clang_meta_win", 0);
    CLANG_RULE_WIN = getIntParameter(message, "clang_rule_win", 0);
    CLANG_WIN_SIZE = getIntParameter(message, "clang_win_size", 0);
    COACH = getBoolParameter(message, "coach", false);
    COACH_PORT = getIntParameter(message, "coach_port", 0);
    COACH_W_REFEREE = getBoolParameter(message, "coach_w_referee", false);
    CONNECT_WAIT = getIntParameter(message, "connect_wait", 0);
    CONTROL_RADIUS = getDoubleParameter(message, "control_radius", 0.0);
    DASH_ANGLE_STEP = getDoubleParameter(message, "dash_angle_step", 0.0);
    DASH_POWER_RATE = getDoubleParameter(message, "dash_power_rate", 0.0);
    DROP_BALL_TIME = getIntParameter(message, "drop_ball_time", 0);
    EFFORT_DEC = getDoubleParameter(message, "effort_dec", 0.0);
    EFFORT_DEC_THR = getDoubleParameter(message, "effort_dec_thr", 0.0);
    EFFORT_INC = getDoubleParameter(message, "effort_inc", 0.0);
    EFFORT_INC_THR = getDoubleParameter(message, "effort_inc_thr", 0.0);
    EFFORT_INIT = getDoubleParameter(message, "effort_init", 0.0);
    EFFORT_MIN = getDoubleParameter(message, "effort_min", 0.0);
    EXTRA_HALF_TIME = getBoolParameter(message, "extra_half_time", false);
    EXTRA_STAMINA = getIntParameter(message, "extra_stamina", false);
    FORBID_KICK_OFF_OFFSIDE = getIntParameter(message, "forbid_kick_off_offside", 0);
    FOUL_CYCLES = getIntParameter(message, "foul_cycles", 0);
    FOUL_DETECT_PROBABILITY = getDoubleParameter(message, "foul_detect_probability", 0.0);
    FOUL_EXPONENT = getIntParameter(message, "foul_exponent", 0);
    FREE_KICK_FAULTS = getIntParameter(message, "free_kick_faults", 0);
    FREEFORM_SEND_PERIOD = getIntParameter(message, "freeform_send_period", 0);
    FREEFORM_WAIT_PERIOD = getIntParameter(message, "freeform_wait_period", 0);
    FULLSTATE_L = getBoolParameter(message, "fullstate_l", false);
    FULLSTATE_R = getBoolParameter(message, "fullstate_r", false);
    GAME_LOG_COMPRESSION = getIntParameter(message, "game_log_compression", 0);
    GAME_LOG_DIR = getStringParameter(message, "game_log_dir", "");
    GAME_LOG_FIXED = getIntParameter(message, "game_log_fixed", 0);
    GAME_LOG_FIXED_NAME = getStringParameter(message, "game_log_fixed_name", "");
    GAME_LOG_VERSION = getIntParameter(message, "game_log_version", 0);
    GAME_LOGGING = getBoolParameter(message, "game_logging", false);
    GAME_OVER_WAIT = getIntParameter(message, "game_over_wait", 0);
    GOAL_WIDTH = getDoubleParameter(message, "goal_width", 0.0);
    GOALIE_MAX_MOVES = getIntParameter(message, "goalie_max_moves", 0);
    GOLDEN_GOAL = getBoolParameter(message, "golden_goal", false);
    HALF_TIME = getIntParameter(message, "half_time", 0);
    HEAR_DECAY = getIntParameter(message, "hear_decay", 0);
    HEAR_INC = getIntParameter(message, "hear_inc", 0);
    HEAR_MAX = getIntParameter(message, "hear_max", 0);
    INERTIA_MOMENT = getDoubleParameter(message, "inertia_moment", 0.0);
    KEEPAWAY = getBoolParameter(message, "keepaway", false);
    KEEPAWAY_LENGTH = getIntParameter(message, "keepaway_length", 0);
    KEEPAWAY_LOG_DATED = getBoolParameter(message, "keepaway_log_dated", false);
    KEEPAWAY_LOG_DIR = getStringParameter(message, "keepaway_log_dir", "");
    KEEPAWAY_LOG_FIXED = getIntParameter(message, "keepaway_log_fixed", 0);
    KEEPAWAY_LOG_FIXED_NAME = getStringParameter(message, "keepaway_log_fixed_name", "");
    KEEPAWAY_LOGGING = getBoolParameter(message, "keepaway_logging", false);
    KEEPAWAY_START = getIntParameter(message, "keepaway_start", 0);
    KEEPAWAY_WIDTH = getIntParameter(message, "keepaway_width", 0);
    KICK_OFF_WAIT = getIntParameter(message, "kick_off_wait", 0);
    KICK_POWER_RATE = getDoubleParameter(message, "kick_power_rate", 0.0);
    KICK_RAND = getDoubleParameter(message, "kick_rand", 0.0);
    KICK_RAND_FACTOR_L = getDoubleParameter(message, "kick_rand_factor_l", 0.0);
    KICK_RAND_FACTOR_R = getDoubleParameter(message, "kick_rand_factor_r", 0.0);
    KICKABLE_MARGIN = getDoubleParameter(message, "kickable_margin", 0.0);
    LANDMARK_FILE = getStringParameter(message, "landmark_file", "");
    LOG_DATE_FORMAT = getStringParameter(message, "log_date_format", "");
    LOG_TIMES = getBoolParameter(message, "log_times", false);
    MAX_BACK_TACKLE_POWER = getDoubleParameter(message, "max_back_tackle_power", 0.0);
    MAX_DASH_ANGLE = getDoubleParameter(message, "max_dash_angle", 0.0);
    MAX_DASH_POWER = getDoubleParameter(message, "max_dash_power", 0.0);
    MAX_GOAL_KICKS = getIntParameter(message, "max_goal_kicks", 0);
    MAX_TACKLE_POWER = getDoubleParameter(message, "max_tackle_power", 0.0);
    MAXMOMENT = getDoubleParameter(message, "maxmoment", 0.0);
    MAXNECKANG = getDoubleParameter(message, "maxneckang", 0.0);
    MAXNECKMOMENT = getDoubleParameter(message, "maxneckmoment", 0.0);
    MAXPOWER = getDoubleParameter(message, "maxpower", 0.0);
    MIN_DASH_ANGLE = getDoubleParameter(message, "min_dash_angle", 0.0);
    MIN_DASH_POWER = getDoubleParameter(message, "min_dash_power", 0.0);
    MINMOMENT = getDoubleParameter(message, "minmoment", 0.0);
    MINNECKANG = getDoubleParameter(message, "minneckang", 0.0);
    MINNECKMOMENT = getDoubleParameter(message, "minneckmoment", 0.0);
    MINPOWER = getDoubleParameter(message, "minpower", 0.0);
    NR_EXTRA_HALFS = getIntParameter(message, "nr_extra_halfs", 0);
    NR_NORMAL_HALFS = getIntParameter(message, "nr_normal_halfs", 0);
    OFFSIDE_ACTIVE_AREA_SIZE = getDoubleParameter(message, "offside_active_area_size", 0.0);
    OFFSIDE_KICK_MARGIN = getDoubleParameter(message, "offside_kick_margin", 0.0);
    OLCOACH_PORT = getIntParameter(message, "olcoach_port", 0);
    OLD_COACH_HEAR = getIntParameter(message, "old_coach_hear", 0);
    PEN_ALLOW_MULT_KICKS = getBoolParameter(message, "pen_allow_mult_kicks", false);
    PEN_BEFORE_SETUP_WAIT = getIntParameter(message, "pen_before_setup_wait", 0);
    PEN_COACH_MOVES_PLAYERS = getIntParameter(message, "pen_coach_moves_players", 0);
    PEN_DIST_X = getDoubleParameter(message, "pen_dist_x", 0.0);
    PEN_MAX_EXTRA_KICKS = getIntParameter(message, "pen_max_extra_kicks", 0);
    PEN_MAX_GOALIE_DIST_X = getDoubleParameter(message, "pen_max_goalie_dist_x", 0.0);
    PEN_NR_KICKS = getIntParameter(message, "pen_nr_kicks", 0);
    PEN_RANDOM_WINNER = getDoubleParameter(message, "pen_random_winner", 0.0);
    PEN_READY_WAIT = getIntParameter(message, "pen_ready_wait", 0);
    PEN_SETUP_WAIT = getIntParameter(message, "pen_setup_wait", 0);
    PEN_TAKEN_WAIT = getIntParameter(message, "pen_taken_wait", 0);
    PENALTY_SHOOT_OUTS = getIntParameter(message, "penalty_shoot_outs", 0);
    PLAYER_ACCEL_MAX = getDoubleParameter(message, "player_accel_max", 0.0);
    PLAYER_DECAY = getDoubleParameter(message, "player_decay", 0.0);
    PLAYER_RAND = getDoubleParameter(message, "player_rand", 0.0);
    PLAYER_SIZE = getDoubleParameter(message, "player_size", 0.0);
    PLAYER_SPEED_MAX = getDoubleParameter(message, "player_speed_max", 0.0);
    PLAYER_SPEED_MAX_MIN = getDoubleParameter(message, "player_speed_max_min", 0.0);
    PLAYER_WEIGHT = getDoubleParameter(message, "player_weight", 0.0);
    POINT_TO_BAN = getIntParameter(message, "point_to_ban", 0);
    POINT_TO_DURATION = getIntParameter(messsage, "point_to_duration", 0);
    PORT = getIntParameter(message, "port", 0);
    PRAND_FACTOR_L = getIntParameter(message, "prand_factor_l", 0);
    PRAND_FACTOR_R = getIntParameter(message, "prand_factor_r", 0);
    PROFILE = getIntParameter(message, "profile", 0);
    PROPER_GOAL_KICKS = getIntParameter(message, "proper_goal_kicks", 0);
    QUANTIZE_STEP = getDoubleParameter(message, "quantize_step", 0.0);
    QUANTIZE_STEP_L = getDoubleParameter(message, "quantize_step_l", 0.0);
    RECORD_MESSAGES = getIntParameter(message, "record_messages", 0);
    RECOVER_DEC = getDoubleParameter(message, "recover_dec", 0.0);
    RECOVER_DEC_THR = getDoubleParameter(message, "recover_dec_thr", 0.0);
    RECOVER_INIT = getDoubleParameter(message, "recover_init", 0.0);
    RECOVER_MIN = getDoubleParameter(message, "recover_min", 0.0);
    RECV_STEP = getIntParameter(message, "recv_step", 0);
    RED_CARD_PROBABILITY = getDoubleParameter(message, "red_card_probability", 0.0);
    SAY_COACH_CNT_MAX = getIntParameter(message, "say_coach_cnt_max", 0);
    SAY_COACH_MSG_SIZE = getIntParameter(message, "say_coach_msg_size", 0);
    SEND_COMMS = getIntParameter(message, "send_comms", 0);
    SEND_STEP = getIntParameter(message, "send_step", 0);
    SEND_VI_STEP = getIntParameter(message, "send_vi_step", 0);
    SENSE_BODY_STEP = getIntParameter(message, "sense_body_step", 0);
    SIDE_DASH_RATE = getDoubleParameter(message, "side_dash_rate", 0.0);
    SIMULATOR_STEP = getIntParameter(message, "simulator_step", 0);
    SLOWNESS_ON_TOP_FOR_LEFT_TEAM = getDoubleParameter(message, "slowness_on_top_for_left_team", 0.0);
    SLOWNESS_ON_TOP_FOR_RIGHT_TEAM = getDoubleParameter(message, "slowness_on_top_for_right_team", 0.0);
    STAMINA_CAPACITY = getIntParameter(message, "stamina_capacity", 0);
    STAMINA_INC_MAX = getIntParameter(message, "stamina_inc_max", 0);
    STAMINA_MAX = getIntParameter(message, "stamina_max", 0);
    START_GOAL_L = getIntParameter(message, "start_goal_l", 0);
    START_GOAL_R = getIntParameter(message, "start_goal_r", 0);
    STOPPED_BALL_VEL = getDoubleParameter(message, "stopped_ball_vel", 0.0);
    SYNCH_MICRO_SLEEP = getIntParameter(message, "synch_micro_sleep", 0);
    SYNCH_MODE = getBoolParameter(message, "synch_mode", false);
    SYNCH_OFFSET = getIntParameter(message, "synch_offset", 0);
    SYNCH_SEE_OFFSET = getIntParameter(message, "synch_see_offset", 0);
    TACKLE_BACK_DIST = getDoubleParameter(message, "tackle_back_dist", 0.0);
    TACKLE_CYCLES = getIntParameter(message, "tackle_cycles", 0);
    TACKLE_DIST = getDoubleParameter(message, "tackle_dist", 0.0);
    TACKLE_EXPONENT = getIntParameter(message, "tackle_exponent", 0);
    TACKLE_POWER_RATE = getDoubleParameter(message, "tackle_power_rate", 0.0);
    TACKLE_RAND_FACTOR = getDoubleParameter(message, "tackle_rand_factor", 0.0);
    TACKLE_WIDTH = getDoubleParameter(message, "tackle_width", 0.0);
    TEAM_ACTUATOR_NOISE = getDoubleParameter(message, "team_actuator_noise", 0.0);
    TEAM_L_START = getStringParameter(message, "team_l_start", "");
    TEAM_R_START = getStringParameter(message, "team_r_start", "");
    TEXT_LOG_COMPRESSION = getBoolParameter(message, "text_log_compression", false);
    TEXT_LOG_DATED = getBoolParameter(message, "text_log_dated", false);
    TEXT_LOG_DIR = getStringParameter(message, "text_log_dir", "");
    TEXT_LOG_FIXED = getIntParameter(message, "text_log_fixed", 0);
    TEXT_LOG_FIXED_NAME = getStringParameter(message, "text_log_fixed_name", "");
    TEXT_LOGGING = getBoolParameter(message, "text_logging", false);
    USE_OFFSIDE = getBoolParameter(message, "use_offside", false);
    VERBOSE = getBoolParameter(message, "verbose", false);
    VISIBLE_ANGLE = getDoubleParameter(message, "visible_angle", 0.0);
    VISIBLE_DISTANCE = getDoubleParameter(message, "visible_distance", 0.0);
    WIND_ANG = getDoubleParameter(message, "wind_ang", 0.0);
    WIND_DIR = getDoubleParameter(message, "wind_dir", 0.0);
    WIND_FORCE = getDoubleParameter(message, "wind_force", 0.0);
    WIND_NONE = getDoubleParameter(message, "wind_none", 0.0);
    WIND_RAND = getDoubleParameter(message, "wind_rand", 0.0);
    WIND_RANDOM = getDoubleParameter(message, "wind_random", 0.0);
}

}

} // namespace Olamani