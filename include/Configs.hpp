#ifndef CONFIGS_HPP
#define CONFIGS_HPP

#include <string>

namespace Olamani {

namespace Configs {

std::string server;
int port;

void loadConfigsFile(std::string pathfile);
void loadConfigsFile();

} // namespace Configs

} // namespace Olamani

#endif // CONFIGS_HPP
