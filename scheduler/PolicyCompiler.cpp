#include "PolicyCompiler.hpp"

namespace timescend::scheduler {

Policy PolicyCompiler::compile(const std::string& source) const {
    Policy policy{};
    policy.name = source;
    return policy;
}

} // namespace timescend::scheduler
