#pragma once

#include <string>

namespace timescend::system {

class StartupManager {
public:
    bool registerService(const std::string& serviceName) const;
};

} // namespace timescend::system
