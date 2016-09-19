#ifndef BODY_HPP
#define BODY_HPP

#include <string>
#include <list>

namespace Olamani {

namespace Body {

extern std::string TEAM_NAME;
extern int         UNIFORM_NUMBER;
extern char        SIDE;
extern bool        ALLOW_MULT_DEFAULT_TYPE;
extern double      CATCHABLE_AREA_L_STRETCH_MAX;
extern double      CATCHABLE_AREA_L_STRETCH_MIN;
extern double      DASH_POWER_RATE_DELTA_MAX;
extern double      DASH_POWER_RATE_DELTA_MIN;
extern double      EFFORT_MAX_DELTA_FACTOR;
extern double      EFFORT_MIN_DELTA_FACTOR;
extern double      EXTRA_STAMINA_DELTA_MAX;
extern double      EXTRA_STAMINA_DELTA_MIN;
extern double      FOUL_DETECT_PROBABILITY_DELTA_FACTOR;
extern double      INERTIA_MOMENT_DELTA_FACTOR;
extern double      KICK_POWER_RATE_DELTA_MAX;
extern double      KICK_POWER_RATE_DELTA_MIN;
extern double      KICK_RAND_DELTA_FACTOR;
extern double      KICKABLE_MARGIN_DELTA_MAX;
extern double      KICKABLE_MARGIN_DELTA_MIN;
extern double      NEW_DASH_POWER_RATE_DELTA_MAX;
extern double      NEW_DASH_POWER_RATE_DELTA_MIN;
extern double      NEW_STAMINA_INC_MAX_DELTA_FACTOR;
extern double      PLAYER_DECAY_DELTA_MAX;
extern double      PLAYER_DECAY_DELTA_MIN;
extern double      PLAYER_SIZE_DELTA_FACTOR;
extern double      PLAYER_SPEED_MAX_DELTA_MAX;
extern double      PLAYER_SPEED_MAX_DELTA_MIN;
extern int         PLAYER_TYPES;
extern int         PT_MAX;
extern int         RANDOM_SEED;
extern double      STAMINA_INC_MAX_DELTA_FACTOR;
extern int         SUBS_MAX;

extern double      AMOUNT_OF_SPEED;
extern double      ANGLE_VIEW;
extern int         ARM_COUNT;
extern double      ARM_DIRECTION;
extern double      ARM_DISTANCE;
extern int         ARM_EXPIRES;
extern bool        ARM_MOVABLE;
extern int         CATCH_COUNT;
extern double      CATCHABLE_AREA_L_STRETCH;
extern int         CHANGE_VIEW_COUNT;
extern std::list<std::string> COLLISIONS;
extern int         DASH_COUNT;
extern double      DASH_POWER_RATE;
extern double      DIRECTION_OF_SPEED;
extern double      EFFORT;
extern double      EFFORT_MAX;
extern double      EFFORT_MIN;
extern double      EXTRA_STAMINA;
extern int         FOCUS_COUNT;
extern std::string FOCUS_TARGET;
extern std::string FOUL_CARD;
extern bool        FOUL_CHARGED;
extern double      FOUL_DETECT_PROBABILITY;
extern double      HEAD_ANGLE;
extern double      INERTIA_MOMENT;
extern int         KICK_COUNT;
extern double      KICK_POWER_RATE;
extern double      KICK_RAND;
extern double      KICKABLE_MARGIN;
extern int         MOVE_COUNT;
extern double      PLAYER_DECAY;
extern double      PLAYER_SIZE;
extern double      PLAYER_SPEED_MAX;
extern int         SAY_COUNT;
extern double      STAMINA;
extern double      STAMINA_CAPACITY;
extern double      STAMINA_INC_MAX;
extern int         TACKLE_COUNT;
extern int         TACKLE_EXPIRES;
extern int         TURN_COUNT;
extern int         TURN_NECK_COUNT;
extern int         TYPE_ID;
extern std::string VIEW_MODE_QUALITY;
extern std::string VIEW_MODE_WIDTH;

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
void clearTypes();
void changePlayerType(int type);
void handleBodyMessage(std::string message);

} // namespace Body

} // namespace Olamani

#endif // BODY_HPP
