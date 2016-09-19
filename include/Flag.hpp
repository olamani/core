#ifndef FLAG_HPP
#define FLAG_HPP

#include <string>

namespace Olamani {

class Flag {
private:
    std::string name;
public:
    Flag();
    ~Flag();
    void setData(std::string name, std::string position);
    double x;
    double y;
    double direction;
    double distance;
};

} // namespace Olamani

#endif // FLAG_HPP