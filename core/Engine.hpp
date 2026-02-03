#pragma once

#include <atomic>
#include <memory>
#include <thread>

#include "ActionDispatcher.hpp"
#include "EventBus.hpp"
#include "ModeController.hpp"
#include "StateManager.hpp"

namespace timescend::core {

class Engine {
public:
    Engine();
    ~Engine();

    void start();
    void stop();

    EventBus& eventBus();
    StateManager& stateManager();
    ModeController& modeController();
    ActionDispatcher& actionDispatcher();

private:
    void runLoop();

    std::atomic<bool> running_{false};
    std::thread worker_{};
    EventBus eventBus_{};
    StateManager stateManager_{};
    ModeController modeController_{};
    ActionDispatcher actionDispatcher_{};
};

} // namespace timescend::core
