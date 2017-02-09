#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

namespace Olamani {

enum PlayerTeam {
    UNKNOWN,
    OUR,
    OPP
};

class Player {
private:
    double x;
    double y;
    double direction;
    double distance;
    double direction_change;
    double distance_change;
    double body_direction;
    double head_direction;
    double point_direction;
    bool is_kicking;
    bool is_tackling;
    bool is_goalie;
    bool is_pointing;
    PlayerTeam player_team;
    int number;
public:
    Player(): x(0.0), 
              y(0.0), 
              direction(0.0), 
              distance(100.0), 
              direction_change(0.0), 
              distance_change(0.0),
              body_direction(0.0),
              head_direction(0.0),
              point_direction(0.0),
              is_kicking(false),
              is_tackling(false),
              is_goalie(false),
              is_pointing(false),
              player_team(UNKNOWN),
              number(0) {};
    ~Player() {};
    void setData(std::string name, std::string position);
    void localize(double x, double y, double vx, double vy);
    double getDirection();
    double getDistance();
    double getDirectionChange();
    double getDistanceChange();
    double getHeadDirection();
    double getBodyDirection();
    double getPointDirection();
    bool isKicking();
    bool isTackling();
    bool isGoalie();
    bool isPointing();
    PlayerTeam getTeam();
    int getNumber();
};

} // namespace Olamani

#endif // PLAYER_HPP