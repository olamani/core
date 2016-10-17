#include "Player.hpp"
#include "Body.hpp"
#include <string>
#include <sstream>
#include <vector>

namespace Olamani {

Player::Player() {

}

Player::~Player() {

}

void Player::setData(std::string name, std::string position) {
    std::vector<std::string> name_tokens;
    std::vector<std::string> position_tokens;
    std::stringstream ss_name(name);
    std::srtingstream ss_position(position);
    std::string token;
    while (std::getline(ss_name, token, ' ')) {
        name_tokens.push_back(token);
    }
    while (std::getline(ss_position, token, ' ')) {
        switch (token[0]) {
        case 'k':
            is_kicking = true;
            break;
        case 't':
            is_tackling = true;
            break;
        default:
            position_tokens.push_back(token);
        }
    }
    std::string team;
    switch (name_tokens.size()) {
    case 4:
        is_goalie = true;
    case 3:
        number = std::stoi(token[2]);
    case 2:
        team = name_tokens[1].substr(1, tokens[1].length() - 2);
        if (team.compare(Body::TEAM) == 0) {
            player_team = OUR;
        } else {
            player_team = OPP;
        }
        break;
    default:
        break;
    }
    switch (position_tokens.size()) {
    case 1:
        direction = std::stof(position_tokens[0]);
        break;
    case 2:
        distance = std::stof(position_tokens[0]);
        direction = std::stof(position_tokens[1]);
        break;
    case 3:
        distance = std::stof(position_tokens[0]);
        direction = std::stof(position_tokens[1]);
        point_direction = std::stof(position_tokens[2]);
        is_pointing = true;
        break;
    case 4:
        distance = std::stof(position_tokens[0]);
        direction = std::stof(position_tokens[1]);
        distance_change = std::stof(position_tokens[2]);
        direction_change = std::stof(position_tokens[3]);
        break;
    case 5:
        distance = std::stof(position_tokens[0]);
        direction = std::stof(position_tokens[1]);
        distance_change = std::stof(position_tokens[2]);
        direction_change = std::stof(position_tokens[3]);
        point_direction = std::stof(position_tokens[4]);
        is_pointing = true;
        break;
    case 6:
        distance = std::stof(position_tokens[0]);
        direction = std::stof(position_tokens[1]);
        distance_change = std::stof(position_tokens[2]);
        direction_change = std::stof(position_tokens[3]);
        body_direction = std::stof(position_tokens[4]);
        head_direction = std::stof(position_tokens[5]);
        break;
    case 7:
        distance = std::stof(position_tokens[0]);
        direction = std::stof(position_tokens[1]);
        distance_change = std::stof(position_tokens[2]);
        direction_change = std::stof(position_tokens[3]);
        body_direction = std::stof(position_tokens[4]);
        head_direction = std::stof(position_tokens[5]);
        point_direction = std::stof(position_tokens[6]);
        is_pointing = true;
        break;
    }
}

void Player::localize(double x, double y, double vx, double vy) {

}

double Player::getDistance() {
    return distance;
}

double Player::getDirection() {
    return direction;
}

} // namespace Olamani