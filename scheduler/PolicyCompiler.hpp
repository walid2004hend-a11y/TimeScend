#pragma once

#include <string>

#include "PolicyTypes.hpp"

namespace timescend::scheduler {

class PolicyCompiler {
public:
    Policy compile(const std::string& source) const;
};

} // namespace timescend::scheduler
