#include "EventBus.hpp"

namespace timescend::core {

void EventBus::publish(const Event& event) {
    std::vector<EventHandler> snapshot;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        snapshot = handlers_;
    }
    for (const auto& handler : snapshot) {
        handler(event);
    }
}

void EventBus::subscribe(EventHandler handler) {
    std::lock_guard<std::mutex> lock(mutex_);
    handlers_.push_back(std::move(handler));
}

} // namespace timescend::core
