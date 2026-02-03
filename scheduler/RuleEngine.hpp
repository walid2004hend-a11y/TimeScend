#pragma once

#include <vector>

#include "PolicyTypes.hpp"

namespace timescend::scheduler {

class RuleEngine {
public:
    void addPolicy(const Policy& policy);
    void evaluate();

private:
    std::vector<Policy> policies_{};
};

} // namespace timescend::scheduler
