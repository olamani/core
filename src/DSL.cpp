#include "DSL.hpp"
#include <regex>
#include <string>

namespace Olamani {

namespace DSL {

int getIntParameter(std::string message, std::string parameter, int _default) {
    std::smatch match;
    if (std::regex_search(message, match, std::regex("\\(" + parameter + "\\s+(\\d+)"))) {
        return std::stoi(match[1]);
    }
    return _default;
}

} // namespace DSL

} // namespace Olamani
