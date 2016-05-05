#include "Locks.hpp"

namespace Olamani {

namespace Locks {

std::mutex body_mutex;
std::condition_variable body_condition;

} // namespace Locks

} // namespace Olamani
