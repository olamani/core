#ifndef BODY_HPP
#define BODY_HPP

#include <string>
#include <list>

namespace Olamani {

namespace Body {

std::string TEAM_NAME;
int         UNIFORM_NUMBER;
std::string SIDE;
bool        ALLOW_MULT_DEFAULT_TYPE;
double      CATCHABLE_AREA_L_STRECH_MAX;
double      CATCHABLE_AREA_L_STRECH_MIN;
double      DASH_POWER_RATE_DELTA_MAX;
double      DASH_POWER_RATE_DELTA_MIN;
double      EFFORT_MAX_DELTA_FACTOR;
double      EFFORT_MIN_DELTA_FACTOR;
double      EXTRA_STAMINA_DELTA_MAX;
double      EXTRA_STAMINA_DELTA_MIN;
double      FOUL_DETECT_PROBABILITY_DELTA_FACTOR;
double      INERTIA_MOMENT_DELTA_FACTOR;
double      KICK_POWER_RATE_DELTA_MAX;
double      KICK_POWER_RATE_DELTA_MIN;
double      KICK_RAND_DELTA_FACTOR;
double      KICKABLE_MARGIN_DELTA_MAX;
double      KICKABLE_MARGIN_DELTA_MIN;
double      NEW_DASH_POWER_RATE_DELTA_MAX;
double      NEW_DASH_POWER_RATE_DELTA_MIN;
double      NEW_STAMINA_INC_MAX_DELTA_FACTOR;
double      PLAYER_DECAY_DELTA_MAX;
double      PLAYER_DECAY_DELTA_MIN;
double      PLAYER_SIZE_DELTA_FACTOR;
double      PLAYER_SPEED_MAX_DELTA_MAX;
double      PLAYER_SPEED_MAX_DELTA_MIN;
int         PLAYER_TYPES;
int         PT_MAX;
int         RANDOM_SEED;
double      STAMINA_INC_MAX_DELTA_FACTOR;
int         SUBS_MAX;

double      AMOUNT_OF_SPEED;
double      ANGLE_VIEW;
int         ARM_COUNT;
double      ARM_DIRECTION;
double      ARM_DISTANCE;
int         ARM_EXPIRES;
bool        ARM_MOVABLE;
int         CATCH_COUNT;
double      CATCHABLE_AREA_L_STRETCH;
int         CHANGE_VIEW_COUNT;
std::list<std::string> COLLISIONS;
int         DASH_COUNT;
double      DASH_POWER_RATE;
double      DIRECTION_OF_SPEED;
double      EFFORT;
double      EFFORT_MAX;
double      EFFORT_MIN;
double      EXTRA_STAMINA;
int         FOCUS_COUNT;
std::string FOCUS_TARGET;
std::string FOUL_CARD;
bool        FOUL_CHARGED;
double      FOUL_DETECT_PROBABILITY;
double      HEAD_ANGLE;
double      INERTIA_MOMENT;
int         KICK_COUNT;
double      KICK_POWER_RATE;
double      KICK_RAND;
double      KICKABLE_MARGIN;
int         MOVE_COUNT;
double      PLAYER_DECAY;
double      PLAYER_SIZE;
double      PLAYER_SPEED_MAX;
int         SAY_COUNT;
double      STAMINA;
double      STAMINA_CAPACITY;
double      STAMINA_INC_MAX;
int         TACKLE_COUNT;
int         TACKLE_EXPIRES;
int         TURN_COUNT;
int         TURN_NECK_COUNT;
int         TYPE_ID;
std::string VIEW_MODE_QUALITY;
std::string VIEW_MODE_WIDTH;

double      amountOfSpeed(unsigned int time = 0);
int         armCount(unsigned int time = 0);
double      armDirection(unsigned int time = 0);
double      armDistance(unsigned int time = 0);
int         armExpires(unsigned int time = 0);
bool        armMovable(unsigned int time = 0);
int         catchCount(unsigned int time = 0);
std::list<std::string> collisions(unsigned int time = 0);
int         changeViewCount(unsigned int time = 0);
int         dashCount(unsigned int time = 0);
double      directionOfSpeed(unsigned int time = 0);
double      effort(unsigned int time = 0);
int         focusCount(unsigned int time = 0);
std::string focusTarget(unsigned int time = 0);
std::string foulCard(unsigned int time = 0);
bool        foulCharged(unsigned int time = 0);
double      headAngle(unsigned int time = 0);
int         kickCount(unsigned int time = 0);
int         moveCount(unsigned int time = 0);
int         sayCount(unsigned int time = 0);
double      stamina(unsigned int time = 0);
double      staminaCapacity(unsigned int time = 0);
int         tackleCount(unsigned int time = 0);
int         tackleExpires(unsigned int time = 0);
int         turnCount(unsigned int time = 0);
int         turnNeckCount(unsigned int time = 0);
std::string viewModeQuality(unsigned int time = 0);
std::string viewModeWidth(unsigned int time = 0);

void handleParametersMessage(std::string message);
void handlePlayerTypeMessage(std::string message);
void handleBodyMessage(std::string message);

} // namespace Body

} // namespace Olamani

#endif // BODY_HPP
