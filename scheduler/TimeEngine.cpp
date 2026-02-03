#include "TimeEngine.hpp"

namespace timescend::scheduler {

std::chrono::system_clock::time_point TimeEngine::now() const {
    return std::chrono::system_clock::now();
}

} // namespace timescend::scheduler
