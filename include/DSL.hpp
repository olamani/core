#ifndef DSL_HPP
#define DSL_HPP

#include <string>
#include <list>

namespace Olamani {

namespace DSL {

struct view_mode {
    std::string quality;
    std::string width;
};

struct stamina {
    double stamina;
    double effort;
    double capacity;
};

struct speed {
    double amount;
    double direction;
};

struct arm {
    int movable;
    int expires;
    double distance;
    double direction;
    int count;
};

struct focus {
    std::string target;
    int count;
};

struct tackle {
    int expires;
    int count;
};

struct foul {
    int charged;
    std::string card;
};

struct sense_body {
    int time;
    view_mode view_mode;
    stamina stamina;
    speed speed;
    double head_angle;
    int kick;
    int dash;
    int turn;
    int say;
    int turn_neck;
    int _catch;
    int move;
    int change_view;
    arm arm;
    focus focus;
    tackle tackle;
    std::string collision;
    foul foul;
};

struct object {
    char type;
    std::string name;
    std::string data;
};

struct see {
    int time;
    std::list<object> objects;
};

std::string prepareRegex(std::string prepare);
std::string getSenseBodyRegex();
int getIntParameter(std::string message, std::string parameter, int _default);
double getDoubleParameter(std::string message, std::string parameter, double _default);
bool getBoolParameter(std::string message, std::string parameter, bool _default);
std::string getStringParameter(std::string message, std::string parameter, std::string _default);
sense_body parseSenseBody(std::string message);
see parseSee(std::string message);

} // namespace DSL

} // namespace Olamani

#endif // DSL_HPP
