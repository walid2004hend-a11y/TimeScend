#pragma once

#include <chrono>
#include <functional>
#include <mutex>
#include <string>
#include <variant>
#include <vector>

namespace timescend::core {

struct Event {
    std::string type;
    std::variant<int, bool, std::string> payload;
    std::chrono::system_clock::time_point timestamp;
};

using EventHandler = std::function<void(const Event&)>;

class EventBus {
public:
    void publish(const Event& event);
    void subscribe(EventHandler handler);

private:
    mutable std::mutex mutex_{};
    std::vector<EventHandler> handlers_{};
};

} // namespace timescend::core
