#include "DSL.hpp"
#include <regex>
#include <string>
#include <sstream>
#include <cctype>
#include <unordered_map>
#include <iostream>

namespace Olamani {

namespace DSL {

std::string double_regex = "([\\d\\.\\-e]+)";
std::string int_regex = "(\\d+)";
std::string string_regex = "(\\w+)";
std::unordered_map<char, std::string> regexes = {
    {'t', "(none|[lr]\\s+\\d+)"},
    {'l', "(none|\\(ball\\)|\\(player\\)|\\(post\\)|\\s)+"},
    {'c', "(none|yellow|red)"}
};

std::string sense_body = "(sense_body $i "
    "(view_mode $s $s)$_"
    "(stamina $d $d $d)$_"
    "(speed $d $d)$_"
    "(head_angle $d)$_"
    "(kick $i)$_"
    "(dash $i)$_"
    "(turn $i)$_"
    "(say $i)$_"
    "(turn_neck $i)$_"
    "(catch $i)$_"
    "(move $i)$_"
    "(change_view $i)$_"
    "(arm "
        "(movable $i)$_"
        "(expires $i)$_"
        "(target $d $d)$_"
        "(count $d))$_"
    "(focus "
        "(target $(t))$_"
        "(count $i))$_"
    "(tackle "
        "(expires $i)$_"
        "(count $i))$_"
    "(collision $(l))$_"
    "(foul "
        "(charged $i)$_"
        "(card $(c))))";

std::string prepareRegex(std::string prepare) {
    std::stringstream builder;
    auto it = prepare.begin();
    while (it != prepare.end()) {
        char c = *it;
        if (c == '(') {
            builder << "\\(";
        } else if (c == ')') {
            builder << "\\)";
        } else if (c == ' ') {
            builder << "\\s+";
        } else if (c == '$') {
            it++;
            c = *it;
            switch (c) {
            case 'i':
                builder << int_regex;
                break;
            case 'd':
                builder << double_regex;
                break;
            case 's':
                builder << string_regex;
                break;
            case '_':
                builder << "\\s*";
                break;
            case '(':
                it++;
                c = *it;
                if (c == 't' || c == 'l' || c == 'c') {
                    builder << regexes[c];
                }
                it++; // consume closing parenthesis
                break;
            }
        } else if (isalpha(c) || c == '_') {
            builder << c;
        }
        it++;
    }
    return builder.str();
}

std::string sense_body_regex = prepareRegex(sense_body);

std::string getSenseBodyRegex() {
    return sense_body_regex;
}

int getIntParameter(std::string message, std::string parameter, int _default) {
    std::smatch match;
    if (std::regex_search(message, match, std::regex("\\(" + parameter + "\\s+([\\d\\-]+)\\)"))) {
        return std::stoi(match[1]);
    }
    return _default;
}

double getDoubleParameter(std::string message, std::string parameter, double _default) {
    std::smatch match;
    if (std::regex_search(message, match, std::regex("\\(" + parameter + "\\s+([\\d\\.\\-e]+)\\)"))) {
        return std::stof(match[1]);
    }
    return _default;
}

bool getBoolParameter(std::string message, std::string parameter, bool _default) {
    return getIntParameter(message, parameter, 0) != 0;
}

std::string getStringParameter(std::string message, std::string parameter, std::string _default) {
    std::smatch match;
    if (std::regex_search(message, match, std::regex("\\(" + parameter + "\\s+\"([\\w\\.\\-~%/]+)\"\\)"))) {
        return match[1];
    }
    return _default;
}

} // namespace DSL

} // namespace Olamani
