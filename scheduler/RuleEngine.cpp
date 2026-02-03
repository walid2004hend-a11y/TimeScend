#include "RuleEngine.hpp"

namespace timescend::scheduler {

void RuleEngine::addPolicy(const Policy& policy) {
    policies_.push_back(policy);
}

void RuleEngine::evaluate() {
    for (const auto& policy : policies_) {
        for (const auto& rule : policy.rules) {
            if (rule.condition.predicate && rule.condition.predicate()) {
                if (rule.action.execute) {
                    rule.action.execute();
                }
            }
        }
    }
}

} // namespace timescend::scheduler
