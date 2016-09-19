#include "Flag.hpp"
#include "Body.hpp"
#include <map>
#include <tuple>
#include <string>
#include <sstream>

namespace Olamani {

static const std::map<std::string, std::tuple<double, double> > field {
    {"f t 0",    std::make_pair(  0.0, -39.0)},
    {"f t r 10", std::make_pair( 10.0, -39.0)},
    {"f t r 20", std::make_pair( 20.0, -39.0)},
    {"f t r 30", std::make_pair( 30.0, -39.0)},
    {"f t r 40", std::make_pair( 40.0, -39.0)},
    {"f t r 50", std::make_pair( 50.0, -39.0)},
    {"f r t 30", std::make_pair( 57.5, -30.0)},
    {"f r t 20", std::make_pair( 57.5, -20.0)},
    {"f r t 10", std::make_pair( 57.5, -10.0)},
    {"f r 0",    std::make_pair( 57.5,   0.0)},
    {"f r b 10", std::make_pair( 57.5,  10.0)},
    {"f r b 20", std::make_pair( 57.5,  20.0)},
    {"f r b 30", std::make_pair( 57.5,  30.0)},
    {"f b r 50", std::make_pair( 50.0,  39.0)},
    {"f b r 40", std::make_pair( 40.0,  39.0)},
    {"f b r 30", std::make_pair( 30.0,  39.0)},
    {"f b r 20", std::make_pair( 20.0,  39.0)},
    {"f b r 10", std::make_pair( 10.0,  39.0)},
    {"f b 0",    std::make_pair(  0.0,  39.0)},
    {"f b l 10", std::make_pair(-10.0,  39.0)},
    {"f b l 20", std::make_pair(-20.0,  39.0)},
    {"f b l 30", std::make_pair(-30.0,  39.0)},
    {"f b l 40", std::make_pair(-40.0,  39.0)},
    {"f b l 50", std::make_pair(-50.0,  39.0)},
    {"f l b 30", std::make_pair(-57.5,  30.0)},
    {"f l b 20", std::make_pair(-57.5,  20.0)},
    {"f l b 10", std::make_pair(-57.5,  10.0)},
    {"f l 0",    std::make_pair(-57.5,   0.0)},
    {"f l t 10", std::make_pair(-57.5, -10.0)},
    {"f l t 20", std::make_pair(-57.5, -20.0)},
    {"f l t 30", std::make_pair(-57.5, -30.0)},
    {"f t l 50", std::make_pair(-50.0, -39.0)},
    {"f t l 40", std::make_pair(-40.0, -39.0)},
    {"f t l 30", std::make_pair(-30.0, -39.0)},
    {"f t l 20", std::make_pair(-20.0, -39.0)},
    {"f t l 10", std::make_pair(-10.0, -39.0)},
    {"f c",      std::make_pair(  0.0,   0.0)},
    {"f c t",    std::make_pair(  0.0, -34.0)},
    {"f r t",    std::make_pair( 52.5, -34.0)},
    {"f r b",    std::make_pair( 52.5,  34.0)},
    {"f c b",    std::make_pair(  0.0,  34.0)},
    {"f l b",    std::make_pair(-52.5,  34.0)},
    {"f l t",    std::make_pair(-52.5, -34.0)},
    {"g l",      std::make_pair(-52.5,   0.0)},
    {"f g l t",  std::make_pair(-52.5,  -7.0)},
    {"f p l t",  std::make_pair(-36.0, -20.0)},
    {"f p l c",  std::make_pair(-36.0,   0.0)},
    {"f p l b",  std::make_pair(-36.0,  20.0)},
    {"f g l b",  std::make_pair(-52.5,   7.0)},
    {"g r",      std::make_pair( 52.5,   0.0)},
    {"f g r t",  std::make_pair( 52.5,  -7.0)},
    {"f p r t",  std::make_pair( 36.0, -20.0)},
    {"f p r c",  std::make_pair( 36.0,   0.0)},
    {"f p r b",  std::make_pair( 36.0,  20.0)},
    {"f g r b",  std::make_pair( 52.5,   7.0)}
};

Flag::Flag() {

}

Flag::~Flag() {

}

void Flag::setData(std::string name, std::string position) {
    auto coordinates = field.at(name);
    if (Body::SIDE == 'r') {
        x = -1.0 * std::get<0>(coordinates);
        y = -1.0 * std::get<1>(coordinates);
    } else {
        x = std::get<0>(coordinates);
        y = std::get<1>(coordinates);
    }
    std::stringstream ss(position);
    std::string token;
    std::getline(ss, token, ' ');
    distance = std::stof(token);
    std::getline(ss, token, ' ');
    direction = std::stof(token);
}

} // namespace Olamani