#include "StateManager.hpp"

namespace timescend::core {

SystemState StateManager::state() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return state_;
}

void StateManager::setState(SystemState next) {
    std::lock_guard<std::mutex> lock(mutex_);
    state_ = next;
}

} // namespace timescend::core
