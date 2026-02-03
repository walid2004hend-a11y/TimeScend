#pragma once

#include <string>

namespace timescend::system {

class ProcessKiller {
public:
    bool terminateProcess(const std::string& processName) const;
};

} // namespace timescend::system
