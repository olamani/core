#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

namespace Olamani {

enum PlayerTeam {
    UNKNOWN,
    OUR,
    OPP
}

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
    Player();
    ~Player();
    void setData(std::string name, std::string position);
    void localize(double x, double y, double vx, double vy);
    double getDirection();
    double getDistance();
    bool isKicking();
    bool isTackling();
    bool isGoalie();
    bool isPointing();
    PlayerTeam getTeam();
    int getNumber();
};

} // namespace Olamani

#endif // PLAYER_HPP