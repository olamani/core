#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>

namespace Olamani {

namespace Server {

extern double      AUDIO_CUT_DIST;
extern bool        AUTO_MODE;
extern double      BACK_DASH_RATE;
extern int         BACK_PASSES;
extern double      BALL_ACCEL_MAX;
extern double      BALL_DECAY;
extern double      BALL_RAND;
extern double      BALL_SIZE;
extern double      BALL_SPEED_MAX;
extern double      BALL_STUCK_AREA;
extern double      BALL_WEIGHT;
extern int         CATCH_BAN_CYCLE;
extern double      CATCH_PROBABILITY;
extern double      CATCHABLE_AREA_L;
extern double      CATCHABLE_AREA_W;
extern double      CKICK_MARGIN;
extern int         CLANG_ADVICE_WIN;
extern int         CLANG_DEFINE_WIN;
extern int         CLANG_DEL_WIN; 
extern int         CLANG_INFO_WIN;
extern int         CLANG_MESS_DELAY;
extern int         CLANG_MESS_PER_CYCLE;
extern int         CLANG_META_WIN;
extern int         CLANG_RULE_WIN;
extern int         CLANG_WIN_SIZE;
extern bool        COACH;
extern int         COACH_PORT;
extern bool        COACH_W_REFEREE;
extern int         CONNECT_WAIT;
extern double      CONTROL_RADIUS;
extern double      DASH_ANGLE_STEP;
extern double      DASH_POWER_RATE;
extern int         DROP_BALL_TIME;
extern double      EFFORT_DEC;
extern double      EFFORT_DEC_THR;
extern double      EFFORT_INC;
extern double      EFFORT_INC_THR;
extern double      EFFORT_INIT;
extern double      EFFORT_MIN;
extern int         EXTRA_HALF_TIME;
extern double      EXTRA_STAMINA;
extern int         FORBID_KICK_OFF_OFFSIDE;
extern int         FOUL_CYCLES;
extern double      FOUL_DETECT_PROBABILITY;
extern int         FOUL_EXPONENT;
extern int         FREE_KICK_FAULTS;
extern int         FREEFORM_SEND_PERIOD;
extern int         FREEFORM_WAIT_PERIOD;
extern bool        FULLSTATE_L;
extern bool        FULLSTATE_R;
extern int         GAME_LOG_COMPRESSION;
extern std::string GAME_LOG_DIR;
extern int         GAME_LOG_FIXED;
extern std::string GAME_LOG_FIXED_NAME;
extern int         GAME_LOG_VERSION;
extern bool        GAME_LOGGING;
extern int         GAME_OVER_WAIT;
extern double      GOAL_WIDTH;
extern int         GOALIE_MAX_MOVES;
extern bool        GOLDEN_GOAL;
extern int         HALF_TIME;
extern int         HEAR_DECAY;
extern int         HEAR_INC;
extern int         HEAR_MAX;
extern double      INERTIA_MOMENT;
extern bool        KEEPAWAY;
extern int         KEEPAWAY_LENGTH;
extern bool        KEEPAWAY_LOG_DATED;
extern std::string KEEPAWAY_LOG_DIR;
extern int         KEEPAWAY_LOG_FIXED;
extern std::string KEEPAWAY_LOG_FIXED_NAME;
extern bool        KEEPAWAY_LOGGING;
extern int         KEEPAWAY_START;
extern int         KEEPAWAY_WIDTH;
extern int         KICK_OFF_WAIT;
extern double      KICK_POWER_RATE;
extern double      KICK_RAND;
extern double      KICK_RAND_FACTOR_L;
extern double      KICK_RAND_FACTOR_R;
extern double      KICKABLE_MARGIN;
extern std::string LANDMARK_FILE;
extern std::string LOG_DATE_FORMAT;
extern bool        LOG_TIMES;
extern double      MAX_BACK_TACKLE_POWER;
extern double      MAX_DASH_ANGLE;
extern double      MAX_DASH_POWER;
extern int         MAX_GOAL_KICKS;
extern double      MAX_TACKLE_POWER;
extern double      MAXMOMENT;
extern double      MAXNECKANG;
extern double      MAXNECKMOMENT;
extern double      MAXPOWER;
extern double      MIN_DASH_ANGLE;
extern double      MIN_DASH_POWER;
extern double      MINMOMENT;
extern double      MINNECKANG;
extern double      MINNECKMOMENT;
extern double      MINPOWER;
extern int         NR_EXTRA_HALFS;
extern int         NR_NORMAL_HALFS;
extern double      OFFSIDE_ACTIVE_AREA_SIZE;
extern double      OFFSIDE_KICK_MARGIN;
extern int         OLCOACH_PORT;
extern int         OLD_COACH_HEAR;
extern bool        PEN_ALLOW_MULT_KICKS;
extern int         PEN_BEFORE_SETUP_WAIT;
extern int         PEN_COACH_MOVES_PLAYERS;
extern double      PEN_DIST_X;
extern int         PEN_MAX_EXTRA_KICKS;
extern double      PEN_MAX_GOALIE_DIST_X;
extern int         PEN_NR_KICKS;
extern double      PEN_RANDOM_WINNER;
extern int         PEN_READY_WAIT;
extern int         PEN_SETUP_WAIT;
extern int         PEN_TAKEN_WAIT;
extern int         PENALTY_SHOOT_OUTS;
extern double      PLAYER_ACCEL_MAX;
extern double      PLAYER_DECAY;
extern double      PLAYER_RAND;
extern double      PLAYER_SIZE;
extern double      PLAYER_SPEED_MAX;
extern double      PLAYER_SPEED_MAX_MIN;
extern double      PLAYER_WEIGHT;
extern int         POINT_TO_BAN;
extern int         POINT_TO_DURATION;
extern int         PORT;
extern int         PRAND_FACTOR_L;
extern int         PRAND_FACTOR_R;
extern int         PROFILE;
extern int         PROPER_GOAL_KICKS;
extern double      QUANTIZE_STEP;
extern double      QUANTIZE_STEP_L;
extern int         RECORD_MESSAGES;
extern double      RECOVER_DEC;
extern double      RECOVER_DEC_THR;
extern double      RECOVER_INIT;
extern double      RECOVER_MIN;
extern int         RECV_STEP;
extern double      RED_CARD_PROBABILITY;
extern int         SAY_COACH_CNT_MAX;
extern int         SAY_COACH_MSG_SIZE;
extern int         SEND_COMMS;
extern int         SEND_STEP;
extern int         SEND_VI_STEP;
extern int         SENSE_BODY_STEP;
extern double      SIDE_DASH_RATE;
extern int         SIMULATOR_STEP;
extern double      SLOWNESS_ON_TOP_FOR_LEFT_TEAM;
extern double      SLOWNESS_ON_TOP_FOR_RIGHT_TEAM;
extern int         STAMINA_CAPACITY;
extern int         STAMINA_INC_MAX;
extern int         STAMINA_MAX;
extern int         START_GOAL_L;
extern int         START_GOAL_R;
extern double      STOPPED_BALL_VEL;
extern int         SYNCH_MICRO_SLEEP;
extern bool        SYNCH_MODE;
extern int         SYNCH_OFFSET;
extern int         SYNCH_SEE_OFFSET;
extern double      TACKLE_BACK_DIST;
extern int         TACKLE_CYCLES;
extern double      TACKLE_DIST;
extern int         TACKLE_EXPONENT;
extern double      TACKLE_POWER_RATE;
extern double      TACKLE_RAND_FACTOR;
extern double      TACKLE_WIDTH;
extern double      TEAM_ACTUATOR_NOISE;
extern std::string TEAM_L_START;
extern std::string TEAM_R_START;
extern bool        TEXT_LOG_COMPRESSION;
extern bool        TEXT_LOG_DATED;
extern std::string TEXT_LOG_DIR;
extern int         TEXT_LOG_FIXED;
extern std::string TEXT_LOG_FIXED_NAME;
extern bool        TEXT_LOGGING;
extern bool        USE_OFFSIDE;
extern bool        VERBOSE;
extern double      VISIBLE_ANGLE;
extern double      VISIBLE_DISTANCE;
extern double      WIND_ANG;
extern double      WIND_DIR;
extern double      WIND_FORCE;
extern double      WIND_NONE;
extern double      WIND_RAND;
extern double      WIND_RANDOM;

void handleServerParameters(std::string message);

} // namespace Server

} // namespace Olamani

#endif // SERVER_HPP
