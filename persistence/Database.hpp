#pragma once

#include <string>

namespace timescend::persistence {

class Database {
public:
    bool connect(const std::string& path);
};

} // namespace timescend::persistence
