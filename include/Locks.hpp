#ifndef LOCKS_HPP
#define LOCKS_HPP

#include <mutex>
#include <condition_variable>

namespace Olamani {

namespace Locks {

std::mutex body_mutex;
std::condition_variable body_condition;

} // namespace Locks

} // namespace Olamani

#endif // LOCKS_HPP
