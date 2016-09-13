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

std::string sense_body_str = "(sense_body $i "
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

std::string sense_body_regex = prepareRegex(sense_body_str);
std::string see_regex = "\\(([^()]+)\\)\\s*([\\d\\.\\-etk\\s]*)";

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

sense_body parseSenseBody(std::string message) {
    sense_body parsed;
    std::smatch match;
    if (std::regex_match(message, match, std::regex(sense_body_regex))) {
        parsed.time = std::stoi(match[1]);
        parsed.view_mode.quality = match[2];
        parsed.view_mode.width = match[3];
        parsed.stamina.stamina = std::stof(match[4]);
        parsed.stamina.effort = std::stof(match[5]);
        parsed.stamina.capacity = std::stof(match[6]);
        parsed.speed.amount = std::stof(match[7]);
        parsed.speed.direction = std::stof(match[8]);
        parsed.head_angle = std::stof(match[9]);
        parsed.kick = std::stoi(match[10]);
        parsed.dash = std::stoi(match[11]);
        parsed.turn = std::stoi(match[12]);
        parsed.say = std::stoi(match[13]);
        parsed.turn_neck = std::stoi(match[14]);
        parsed._catch = std::stoi(match[15]);
        parsed.move = std::stoi(match[16]);
        parsed.change_view = std::stoi(match[17]);
        parsed.arm.movable = std::stoi(match[18]);
        parsed.arm.expires = std::stoi(match[19]);
        parsed.arm.distance = std::stoi(match[20]);
        parsed.arm.direction = std::stoi(match[21]);
        parsed.arm.count = std::stoi(match[22]);
        parsed.focus.target = match[23];
        parsed.focus.count = std::stoi(match[24]);
        parsed.tackle.expires = std::stoi(match[25]);
        parsed.tackle.count = std::stoi(match[26]);
        parsed.collision = match[27];
        parsed.foul.charged = std::stoi(match[28]);
        parsed.foul.card = match[29];
    }
    return parsed;
}

see parseSee(std::string message) {
    see see;
    std::smatch match;
    while (std::regex_search(message, match, std::regex(see_regex))) {
        object object;
        object.name = match[1];
        object.type = object.name[0];
        object.data = match[2];
        see.objects.push_back(object);
        message = match.suffix();
    }
    return see;
}

} // namespace DSL

} // namespace Olamani
