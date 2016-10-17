#ifndef FLAG_HPP
#define FLAG_HPP

#include <string>

namespace Olamani {

class Flag {
private:
    std::string name;
    double x;
    double y;
    double direction;
    double distance;
public:
    Flag();
    ~Flag();
    void setData(std::string name, std::string position);
    double getX();
    double getY();
    double getDirection();
    double getDistance();
};

} // namespace Olamani

#endif // FLAG_HPP