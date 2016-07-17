#include "DSL.hpp"
#include <regex>
#include <string>
#include <sstream>
#include <cctype>

namespace Olamani {

namespace DSL {

bool islparenthesis(char c) {
    return c == '(';
}

bool isrparenthesis(char c) {
    return c == ')';
}

std::string double_regex = "([\\d\\.\\-e]+)";
std::string int_regex = "(\\d+)";
std::string string_regex = "(\\w+)";

std::string sense_body = "(sense_body $i (parameter $d)$_(parameter $d))";

std::string prepareRegex(std::string prepare) {
    std::stringstream builder;
    auto it = prepare.begin();
    while (it != prepare.end()) {
        char c = *it;
        if (islparenthesis(c)) {
            builder << "\\(";
        } else if (isrparenthesis(c)) {
            builder << "\\)";
        } else if (c == ' ') {
            builder << "\\s+"
        } else if (c == '$') {
            it++;
            c = *it;
            switch (c) {
            case 'i':
                builder << int_regex;
            case 'd':
                builder << double_regex;
            case 's':
                builder << string_regex;
            case '_':
                builder << "\\s*";
            }
        } else if (isalpha(c) || c == '_') {
            builder << c;
        }
        it++;
    }
    return builder.str();
}

boost::regex sense_body_regex(prepareRegex(sense_body));

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
