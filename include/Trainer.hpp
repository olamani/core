#ifndef TRAINER_HPP
#define TRAINER_HPP

#include <string>

namespace Olamani {

namespace Trainer {

void loadScript(std::string filepath);
bool parseScript(std::string script);
void reset();
void onNewCycle(int time);

}

}

#endif // TRAINER_HPP