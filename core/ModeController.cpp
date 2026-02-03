#include "ModeController.hpp"

namespace timescend::core {

void ModeController::registerMode(SystemState state, std::shared_ptr<IMode> mode) {
    std::lock_guard<std::mutex> lock(mutex_);
    modes_[state] = std::move(mode);
}

void ModeController::transitionTo(SystemState next) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (active_) {
        active_->onExit();
    }
    auto it = modes_.find(next);
    if (it != modes_.end()) {
        active_ = it->second;
        active_->onEnter();
    } else {
        active_.reset();
    }
}

} // namespace timescend::core
