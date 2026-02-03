#pragma once

#include <functional>
#include <string>
#include <vector>

namespace timescend::scheduler {

struct Condition {
    std::function<bool()> predicate;
};

struct Action {
    std::function<void()> execute;
};

struct Rule {
    Condition condition;
    Action action;
};

struct Policy {
    std::string name;
    std::vector<Rule> rules;
};

} // namespace timescend::scheduler
