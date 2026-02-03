#pragma once

#include <chrono>

namespace timescend::scheduler {

class TimeEngine {
public:
    std::chrono::system_clock::time_point now() const;
};

} // namespace timescend::scheduler
