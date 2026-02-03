#include "Engine.hpp"

#include <chrono>

namespace timescend::core {

Engine::Engine() = default;

Engine::~Engine() {
    stop();
}

void Engine::start() {
    if (running_.exchange(true)) {
        return;
    }
    worker_ = std::thread(&Engine::runLoop, this);
}

void Engine::stop() {
    if (!running_.exchange(false)) {
        return;
    }
    if (worker_.joinable()) {
        worker_.join();
    }
}

EventBus& Engine::eventBus() {
    return eventBus_;
}

StateManager& Engine::stateManager() {
    return stateManager_;
}

ModeController& Engine::modeController() {
    return modeController_;
}

ActionDispatcher& Engine::actionDispatcher() {
    return actionDispatcher_;
}

void Engine::runLoop() {
    using namespace std::chrono_literals;
    while (running_) {
        std::this_thread::sleep_for(50ms);
    }
}

} // namespace timescend::core
