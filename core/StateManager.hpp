#pragma once

#include <mutex>

namespace timescend::core {

enum class SystemState {
    Idle,
    Focus,
    Study,
    Sleep,
    Locked
};

class StateManager {
public:
    SystemState state() const;
    void setState(SystemState next);

private:
    mutable std::mutex mutex_{};
    SystemState state_{SystemState::Idle};
};

} // namespace timescend::core
