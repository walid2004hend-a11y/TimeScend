#include "ActionDispatcher.hpp"

namespace timescend::core {

void ActionDispatcher::registerAction(const std::string& name, Action action) {
    actions_[name] = std::move(action);
}

bool ActionDispatcher::dispatch(const std::string& name) const {
    auto it = actions_.find(name);
    if (it == actions_.end()) {
        return false;
    }
    it->second();
    return true;
}

} // namespace timescend::core
