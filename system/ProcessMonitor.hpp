#pragma once

#include <string>
#include <vector>

namespace timescend::system {

class ProcessMonitor {
public:
    std::vector<std::string> runningProcesses() const;
};

} // namespace timescend::system
