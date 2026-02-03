#pragma once

#include <memory>
#include <mutex>
#include <unordered_map>

#include "Interfaces/IMode.hpp"
#include "StateManager.hpp"

namespace timescend::core {

class ModeController {
public:
    void registerMode(SystemState state, std::shared_ptr<IMode> mode);
    void transitionTo(SystemState next);

private:
    mutable std::mutex mutex_{};
    std::unordered_map<SystemState, std::shared_ptr<IMode>> modes_{};
    std::shared_ptr<IMode> active_{};
};

} // namespace timescend::core
