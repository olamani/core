#include <vector>
#include <boost/circular_buffer.hpp>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "Body.hpp"
#include "DSL.hpp"

#define BUFFER 8

namespace Olamani {

namespace Body {

std::string TEAM_NAME = "";
int         UNIFORM_NUMBER = 0;
char        SIDE = 'l';
bool        ALLOW_MULT_DEFAULT_TYPE = false;
double      CATCHABLE_AREA_L_STRETCH_MAX = 0.0;
double      CATCHABLE_AREA_L_STRETCH_MIN = 0.0;
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
    return (time < BUFFER ? collisionsBuffer[time] : std::list<std::string>());
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

void handleParametersMessage(std::string message) {
    ALLOW_MULT_DEFAULT_TYPE = DSL::getBoolParameter(message, "allow_mult_default_type", false);
    CATCHABLE_AREA_L_STRETCH_MAX = DSL::getDoubleParameter(message, "catchable_area_l_stretch_max", 0.0);
    CATCHABLE_AREA_L_STRETCH_MIN = DSL::getDoubleParameter(message, "catchable_area_l_stretch_min", 0.0);
    DASH_POWER_RATE_DELTA_MAX = DSL::getDoubleParameter(message, "dash_power_rate_delta_max", 0.0);
    DASH_POWER_RATE_DELTA_MIN = DSL::getDoubleParameter(message, "dash_power_rate_delta_min", 0.0);
    EFFORT_MAX_DELTA_FACTOR = DSL::getDoubleParameter(message, "effort_max_delta_factor", 0.0);
    EFFORT_MIN_DELTA_FACTOR = DSL::getDoubleParameter(message, "effort_min_delta_factor", 0.0);
    EXTRA_STAMINA_DELTA_MAX = DSL::getDoubleParameter(message, "extra_stamina_delta_max", 0.0);
    EXTRA_STAMINA_DELTA_MIN = DSL::getDoubleParameter(message, "extra_stamina_delta_min", 0.0);
    FOUL_DETECT_PROBABILITY_DELTA_FACTOR = DSL::getDoubleParameter(message, "foul_detect_probability_delta_factor", 0.0);
    INERTIA_MOMENT_DELTA_FACTOR = DSL::getDoubleParameter(message, "inertia_moment_delta_factor", 0.0);
    KICK_POWER_RATE_DELTA_MAX = DSL::getDoubleParameter(message, "kick_power_rate_delta_max", 0.0);
    KICK_POWER_RATE_DELTA_MIN = DSL::getDoubleParameter(message, "kick_power_rate_delta_min", 0.0);
    KICK_RAND_DELTA_FACTOR = DSL::getDoubleParameter(message, "kick_rand_delta_factor", 0.0);
    KICKABLE_MARGIN_DELTA_MAX = DSL::getDoubleParameter(message, "kickable_margin_delta_max", 0.0);
    KICKABLE_MARGIN_DELTA_MIN = DSL::getDoubleParameter(message, "kickable_margin_delta_min", 0.0);
    NEW_DASH_POWER_RATE_DELTA_MAX = DSL::getDoubleParameter(message, "new_dash_power_rate_delta_max", 0.0);
    NEW_DASH_POWER_RATE_DELTA_MIN = DSL::getDoubleParameter(message, "new_dash_power_rate_delta_min", 0.0);
    NEW_STAMINA_INC_MAX_DELTA_FACTOR = DSL::getDoubleParameter(message, "new_stamina_inc_max_delta_factor", 0.0);
    PLAYER_DECAY_DELTA_MAX = DSL::getDoubleParameter(message, "player_decay_delta_max", 0.0);
    PLAYER_DECAY_DELTA_MIN = DSL::getDoubleParameter(message, "player_decay_delta_min", 0.0);
    PLAYER_SIZE_DELTA_FACTOR = DSL::getDoubleParameter(message, "player_size_delta_factor", 0.0);
    PLAYER_SPEED_MAX_DELTA_MAX = DSL::getDoubleParameter(message, "player_speed_max_delta_max", 0.0);
    PLAYER_SPEED_MAX_DELTA_MIN = DSL::getDoubleParameter(message, "player_speed_max_delta_min", 0.0);
    PLAYER_TYPES = DSL::getIntParameter(message, "player_types", 0);
    PT_MAX = DSL::getIntParameter(message, "pt_max", 0);
    RANDOM_SEED = DSL::getIntParameter(message, "random_seed", 0);
    STAMINA_INC_MAX_DELTA_FACTOR = DSL::getDoubleParameter(message, "stamina_inc_max_delta_factor", 0.0);
    SUBS_MAX = DSL::getIntParameter(message, "subs_max", 0);
}

std::vector<double> catchableAreaLStretch;
std::vector<double> dashPowerRate;
std::vector<double> effortMax;
std::vector<double> effortMin;
std::vector<double> extraStamina;
std::vector<double> foulDetectProbability;
std::vector<double> inertiaMoment;
std::vector<double> kickPowerRate;
std::vector<double> kickRand;
std::vector<double> kickableMargin;
std::vector<double> playerDecay;
std::vector<double> playerSize;
std::vector<double> playerSpeedMax;
std::vector<double> staminaIncMax;

void handlePlayerTypeMessage(std::string message) {
    catchableAreaLStretch.push_back(DSL::getDoubleParameter(message, "catchable_area_l_stretch", 0.0));
    dashPowerRate.push_back(DSL::getDoubleParameter(message, "dash_power_rate", 0.0));
    effortMax.push_back(DSL::getDoubleParameter(message, "effort_max", 0.0));
    effortMin.push_back(DSL::getDoubleParameter(message, "effort_min", 0.0));
    extraStamina.push_back(DSL::getDoubleParameter(message, "extra_stamina", 0.0));
    foulDetectProbability.push_back(DSL::getDoubleParameter(message, "foul_detect_probability", 0.0));
    inertiaMoment.push_back(DSL::getDoubleParameter(message, "inertia_moment", 0.0));
    kickPowerRate.push_back(DSL::getDoubleParameter(message, "kick_power_rate", 0.0));
    kickRand.push_back(DSL::getDoubleParameter(message, "kick_rand", 0.0));
    kickableMargin.push_back(DSL::getDoubleParameter(message, "kickable_margin", 0.0));
    playerDecay.push_back(DSL::getDoubleParameter(message, "player_decay", 0.0));
    playerSize.push_back(DSL::getDoubleParameter(message, "player_size", 0.0));
    playerSpeedMax.push_back(DSL::getDoubleParameter(message, "player_speed_max", 0.0));
    staminaIncMax.push_back(DSL::getDoubleParameter(message, "stamina_inc_max", 0.0));
}

void clearTypes() {
    catchableAreaLStretch.clear();
    dashPowerRate.clear();
    effortMax.clear();
    effortMin.clear();
    extraStamina.clear();
    foulDetectProbability.clear();
    inertiaMoment.clear();
    kickPowerRate.clear();
    kickRand.clear();
    kickableMargin.clear();
    playerDecay.clear();
    playerSize.clear();
    playerSpeedMax.clear();
    staminaIncMax.clear();
}

void changePlayerType(int type) {
    if (type < PLAYER_TYPES) {
        CATCHABLE_AREA_L_STRETCH = catchableAreaLStretch[type];
        DASH_POWER_RATE = dashPowerRate[type];
        EFFORT_MAX = effortMax[type];
        EFFORT_MIN = effortMin[type];
        EXTRA_STAMINA = extraStamina[type];
        FOUL_DETECT_PROBABILITY = foulDetectProbability[type];
        INERTIA_MOMENT = inertiaMoment[type];
        KICK_POWER_RATE = kickPowerRate[type];
        KICK_RAND = kickRand[type];
        KICKABLE_MARGIN = kickableMargin[type];
        PLAYER_DECAY = playerDecay[type];
        PLAYER_SIZE = playerSize[type];
        PLAYER_SPEED_MAX = playerSpeedMax[type];
        STAMINA_INC_MAX = staminaIncMax[type];
    }
}

void handleBodyMessage(std::string message) {
    DSL::sense_body parsed = DSL::parseSenseBody(message);
    // amount of speed
    AMOUNT_OF_SPEED = parsed.speed.amount;
    amountOfSpeedBuffer.push_front(parsed.speed.amount);
    // arm count
    ARM_COUNT = parsed.arm.count;
    armCountBuffer.push_front(parsed.arm.count);
    // arm direction
    ARM_DIRECTION = parsed.arm.direction;
    armDirectionBuffer.push_front(parsed.arm.direction);
    // arm distance
    ARM_DISTANCE = parsed.arm.distance;
    armDistanceBuffer.push_front(parsed.arm.distance);
    // arm expires
    ARM_EXPIRES = parsed.arm.expires;
    armExpiresBuffer.push_front(parsed.arm.expires);
    // arm movable
    ARM_MOVABLE = parsed.arm.movable;
    armMovableBuffer.push_front(parsed.arm.movable);
    // catch count
    CATCH_COUNT = parsed._catch;
    catchCountBuffer.push_front(parsed._catch);
    // TODO: push collisions
    // change view
    CHANGE_VIEW_COUNT = parsed.change_view;
    changeViewCountBuffer.push_front(parsed.change_view);
    // dash count
    DASH_COUNT = parsed.dash;
    dashCountBuffer.push_front(parsed.dash);
    // direction of speed
    DIRECTION_OF_SPEED = parsed.speed.direction;
    directionOfSpeedBuffer.push_front(parsed.speed.direction);
    // effort
    EFFORT = parsed.stamina.effort;
    effortBuffer.push_front(parsed.stamina.effort);
    // focus count
    FOCUS_COUNT = parsed.focus.count;
    focusCountBuffer.push_front(parsed.focus.count);
    // focus target
    FOCUS_TARGET = parsed.focus.target;
    focusTargetBuffer.push_front(parsed.focus.target);
    // foul card
    FOUL_CARD = parsed.foul.card;
    foulCardBuffer.push_front(parsed.foul.card);
    // foul charged
    FOUL_CHARGED = parsed.foul.charged;
    foulChargedBuffer.push_front(parsed.foul.charged);
    // head angle
    HEAD_ANGLE = parsed.head_angle;
    headAngleBuffer.push_front(parsed.head_angle);
    // kick count
    KICK_COUNT = parsed.kick;
    kickCountBuffer.push_front(parsed.kick);
    // move count
    MOVE_COUNT = parsed.move;
    moveCountBuffer.push_front(parsed.move);
    // say count
    SAY_COUNT = parsed.say;
    sayCountBuffer.push_front(parsed.say);
    // stamina
    STAMINA = parsed.stamina.stamina;
    staminaBuffer.push_front(parsed.stamina.stamina);
    // stamina capacity
    STAMINA_CAPACITY = parsed.stamina.capacity;
    staminaCapacityBuffer.push_front(parsed.stamina.capacity);
    // tackle count
    TACKLE_COUNT = parsed.tackle.count;
    tackleCountBuffer.push_front(parsed.tackle.count);
    // tackle expires
    TACKLE_EXPIRES = parsed.tackle.expires;
    tackleExpiresBuffer.push_front(parsed.tackle.expires);
    // turn count
    TURN_COUNT = parsed.turn;
    turnCountBuffer.push_front(parsed.turn);
    // turn neck count
    TURN_NECK_COUNT = parsed.turn_neck;
    turnNeckCountBuffer.push_front(parsed.turn_neck);
    // view mode quality
    VIEW_MODE_QUALITY = parsed.view_mode.quality;
    viewModeQualityBuffer.push_front(parsed.view_mode.quality);
    // view mode width
    VIEW_MODE_WIDTH = parsed.view_mode.width;
    viewModeWidthBuffer.push_front(parsed.view_mode.width);
    std::cout << "Parsed sense body at time " << parsed.time << std::endl;
}

static std::mutex mutex;
static std::condition_variable condition;
static std::string message;
static std::thread thread;
static bool ready = false;
static bool running = false;

void loop() {
    while (running) {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, []{ return ready; });
        if (message.length() != 0) {
            handleBodyMessage(message);
        }
        ready = false;
        lock.unlock();
    }
}

void start() {
    running = true;
    thread = std::thread(loop);
    std::cout << "Body loop started" << std::endl;
}

void sendMessage(std::string message_) {
    message = message_;
    std::lock_guard<std::mutex> lock(mutex);
    ready = true;
    condition.notify_one();
}

void stop() {
    running = false;
    sendMessage("");
    thread.join();
    std::cout << "Body loop stopped" << std::endl;
}

} // namespace Body

} // namespace Olamani
