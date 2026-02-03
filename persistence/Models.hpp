#pragma once

#include <string>

namespace timescend::persistence {

struct PolicyRecord {
    int id{};
    std::string name;
};

} // namespace timescend::persistence
