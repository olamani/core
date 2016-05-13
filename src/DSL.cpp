#include "DSL.hpp"
#include <regex>
#include <string>

namespace Olamani {

namespace DSL {

int getIntParameter(std::string message, std::string parameter, int _default) {
    std::smatch match;
    if (std::regex_search(message, match, std::regex("\\(" + parameter + "\\s+(\\d+)\\)"))) {
        return std::stoi(match[1]);
    }
    return _default;
}

double getDoubleParameter(std::string message, std::string parameter, double _default) {
    std::smatch match;
    if (std::regex_search(message, match, std::regex("\\(" + parameter + "\\s+([\\d\\.\\-e])\\)"))) {
        return std::stof(match[1]);
    }
    return _default;
}

bool getBoolParameter(std::string message, std::string parameter, bool _default) {
    return getIntParameter(message, parameter, 0) != 0;
}

std::string getStringParameter(std::string message, std::string parameter, std::string _default) {
    std::smatch match;
    if (std::regex_search(message, match, std::regex("\\(" + parameter + "\\s+(\\w+)\\)"))) {
        return match[1];
    }
    return _default;
}

} // namespace DSL

} // namespace Olamani
