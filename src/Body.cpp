#include <boost/circular_buffer.hpp>
#include "Body.hpp"
#define BUFFER 8

namespace Olamani {

namespace Body {

std::string TEAM_NAME = "";
int         UNIFORM_NUMBER = 0;
std::string SIDE = "";
bool        ALLOW_MULT_DEFAULT_TYPE = false;
double      CATCHABLE_AREA_L_STRECH_MAX = 0.0;
double      CATCHABLE_AREA_L_STRECH_MIN = 0.0;
double      DASH_POWER_RATE_DELTA_MAX = 0.0;
double      DASH_POWER_RATE_DELTA_MIN = 0.0;
double      EFFORT_MAX_DELTA_FACTOR = 0.0;
double      EFFORT_MIN_DELTA_FACTOR = 0.0;
double      EXTRA_STAMINA_DELTA_MAX = 0.0;
double      EXTRA_STAMINA_DELTA_MIN = 0.0;
double      FOUL_DETECT_PROBABILITY_DELTA_FACTOR = 0.0;
double      INERTIA_MOMENT_DELTA_FACTOR = 0.0;
double      KICK_POWER_RATE_DELTA_MAX = 0.0;
double      KICK_POWER_RATE_DELTA_MIN = 0.0;
double      KICK_RAND_DELTA_FACTOR = 0.0;
double      KICKABLE_MARGIN_DELTA_MAX = 0.0;
double      KICKABLE_MARGIN_DELTA_MIN = 0.0;
double      NEW_DASH_POWER_RATE_DELTA_MAX = 0.0;
double      NEW_DASH_POWER_RATE_DELTA_MIN = 0.0;
double      NEW_STAMINA_INC_MAX_DELTA_FACTOR = 0.0;
double      PLAYER_DECAY_DELTA_MAX = 0.0;
double      PLAYER_DECAY_DELTA_MIN = 0.0;
double      PLAYER_SIZE_DELTA_FACTOR = 0.0;
double      PLAYER_SPEED_MAX_DELTA_MAX = 0.0;
double      PLAYER_SPEED_MAX_DELTA_MIN = 0.0;
int         PLAYER_TYPES = 0;
int         PT_MAX = 0;
int         RANDOM_SEED = 0;
double      STAMINA_INC_MAX_DELTA_FACTOR = 0.0;
int         SUBS_MAX = 0;

double      AMOUNT_OF_SPEED = 0.0;
double      ANGLE_VIEW = 0.0;
int         ARM_COUNT = 0;
double      ARM_DIRECTION = 0.0;
double      ARM_DISTANCE = 0.0;
int         ARM_EXPIRES = 0;
bool        ARM_MOVABLE = false;
int         CATCH_COUNT = 0;
double      CATCHABLE_AREA_L_STRETCH = 0.0;
int         CHANGE_VIEW_COUNT = 0;
std::list<std::string> COLLISIONS;
int         DASH_COUNT = 0;
double      DASH_POWER_RATE = 0.0;
double      DIRECTION_OF_SPEED = 0.0;
double      EFFORT = 0.0;
double      EFFORT_MAX = 0.0;
double      EFFORT_MIN = 0.0;
double      EXTRA_STAMINA = 0.0;
int         FOCUS_COUNT = 0;
std::string FOCUS_TARGET = "";
std::string FOUL_CARD = "";
bool        FOUL_CHARGED = false;
double      FOUL_DETECT_PROBABILITY = 0.0;
double      HEAD_ANGLE = 0.0;
double      INERTIA_MOMENT = 0.0;
int         KICK_COUNT = 0;
double      KICK_POWER_RATE = 0.0;
double      KICK_RAND = 0.0;
double      KICKABLE_MARGIN = 0.0;
int         MOVE_COUNT = 0;
double      PLAYER_DECAY = 0.0;
double      PLAYER_SIZE = 0.0;
double      PLAYER_SPEED_MAX = 0.0;
int         SAY_COUNT = 0;
double      STAMINA = 0.0;
double      STAMINA_CAPACITY = 0.0;
double      STAMINA_INC_MAX = 0.0;
int         TACKLE_COUNT = 0;
int         TACKLE_EXPIRES = 0;
int         TURN_COUNT = 0;
int         TURN_NECK_COUNT = 0;
int         TYPE_ID = 0;
std::string VIEW_MODE_QUALITY = "";
std::string VIEW_MODE_WIDTH = "";

boost::circular_buffer<double> amountOfSpeedBuffer(BUFFER);
boost::circular_buffer<int>    armCountBuffer(BUFFER);
boost::circular_buffer<double> armDirectionBuffer(BUFFER);
boost::circular_buffer<double> armDistanceBuffer(BUFFER);
boost::circular_buffer<int>    armExpiresBuffer(BUFFER);
boost::circular_buffer<bool>   armMovableBuffer(BUFFER);
boost::circular_buffer<int>    catchCountBuffer(BUFFER);
boost::circular_buffer<std::list<std::string> > collisionsBuffer(BUFFER);
boost::circular_buffer<int>    changeViewCountBuffer(BUFFER);
boost::circular_buffer<int>    dashCountBuffer(BUFFER);
boost::circular_buffer<double> directionOfSpeedBuffer(BUFFER);
boost::circular_buffer<double> effortBuffer(BUFFER);
boost::circular_buffer<int>    focusCountBuffer(BUFFER);
boost::circular_buffer<std::string> focusTargetBuffer(BUFFER);
boost::circular_buffer<std::string> foulCardBuffer(BUFFER);
boost::circular_buffer<bool>   foulChargedBuffer(BUFFER);
boost::circular_buffer<double> headAngleBuffer(BUFFER);
boost::circular_buffer<int>    kickCountBuffer(BUFFER);
boost::circular_buffer<int>    moveCountBuffer(BUFFER);
boost::circular_buffer<int>    sayCountBuffer(BUFFER);
boost::circular_buffer<double> staminaBuffer(BUFFER);
boost::circular_buffer<double> staminaCapacityBuffer(BUFFER);
boost::circular_buffer<int>    tackleCountBuffer(BUFFER);
boost::circular_buffer<int>    tackleExpiresBuffer(BUFFER);
boost::circular_buffer<int>    turnCountBuffer(BUFFER);
boost::circular_buffer<int>    turnNeckCountBuffer(BUFFER);
boost::circular_buffer<std::string> viewModeQualityBuffer(BUFFER);
boost::circular_buffer<std::string> viewModeWidthBuffer(BUFFER);

double amountOfSpeed(unsigned int time) {
    return (time < BUFFER ? amountOfSpeedBuffer[time] : 0.0);
}

int armCount(unsigned int time) {
    return (time < BUFFER ? armCountBuffer[time] : 0);
}

double armDirection(unsigned int time) {
    return (time < BUFFER ? armDirectionBuffer[time] : 0.0);
}

double armDistance(unsigned int time) {
    return (time < BUFFER ? armDistanceBuffer[time] : 0.0);
}

int armExpires(unsigned int time) {
    return (time < BUFFER ? armExpiresBuffer[time] : 0);
}

bool armMovable(unsigned int time) {
    return (time < BUFFER ? armMovableBuffer[time] : false);
}

int catchCount(unsigned int time) {
    return (time < BUFFER ? catchCountBuffer[time] : 0);
}

std::list<std::string> collisions(unsigned int time) {
    return (time < BUFFER ? collisionsBuffer[time] : std::list());
}

int changeViewCount(unsigned int time) {
    return (time < BUFFER ? changeViewCountBuffer[time] : 0);
}

int dashCount(unsigned int time) {
    return (time < BUFFER ? dashCountBuffer[time] : 0);
}

double directionOfSpeed(unsigned int time) {
    return (time < BUFFER ? directionOfSpeedBuffer[time] : 0.0);
}

double effort(unsigned int time) {
    return (time < BUFFER ? effortBuffer[time] : 0.0);
}

int focusCount(unsigned int time) {
    return (time < BUFFER ? focusCountBuffer[time] : 0);
}

std::string focusTarget(unsigned int time) {
    return (time < BUFFER ? focusTargetBuffer[time] : "");
}

std::string foulCard(unsigned int time) {
    return (time < BUFFER ? foulCardBuffer[time] : "");
}

bool foulCharged(unsigned int time) {
    return (time < BUFFER ? foulChargedBuffer[time] : false);
}

double headAngle(unsigned int time) {
    return (time < BUFFER ? headAngleBuffer[time] : 0.0);
}

int kickCount(unsigned int time) {
    return (time < BUFFER ? kickCountBuffer[time] : 0);
}

int moveCount(unsigned int time) {
    return (time < BUFFER ? moveCountBuffer[time] : 0);
}

int sayCount(unsigned int time) {
    return (time < BUFFER ? sayCountBuffer[time] : 0);
}

double stamina(unsigned int time) {
    return (time < BUFFER ? staminaBuffer[time] : 0.0);
}

double staminaCapacity(unsigned int time) {
    return (time < BUFFER ? staminaCapacityBuffer[time] : 0.0);
}

int tackleCount(unsigned int time) {
    return (time < BUFFER ? tackleCountBuffer[time] : 0);
}

int tackleExpires(unsigned int time) {
    return (time < BUFFER ? tackleExpiresBuffer[time] : 0);
}

int turnCount(unsigned int time) {
    return (time < BUFFER ? turnCountBuffer[time] : 0);
}

int turnNeckCount(unsigned int time) {
    return (time < BUFFER ? turnNeckCountBuffer[time] : 0);
}

std::string viewModeQuality(unsigned int time) {
    return (time < BUFFER ? viewModeQualityBuffer[time] : "");
}

std::string viewModeWidth(unsigned int time) {
    return (time < BUFFER ? viewModeWidthBuffer[time] : "");
}

void handleBodyMessage(std::string message);

} // namespace Body

} // namespace Olamani
