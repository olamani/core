#ifndef DSL_HPP
#define DSL_HPP

#include <string>

namespace Olamani {

namespace DSL {

std::string prepareRegex(std::string prepare);
std::string getSenseBodyRegex();
int getIntParameter(std::string message, std::string parameter, int _default);
double getDoubleParameter(std::string message, std::string parameter, double _default);
bool getBoolParameter(std::string message, std::string parameter, bool _default);
std::string getStringParameter(std::string message, std::string parameter, std::string _default);

} // namespace DSL

} // namespace Olamani

#endif // DSL_HPP
