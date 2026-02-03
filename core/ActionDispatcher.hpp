#pragma once

#include <functional>
#include <string>
#include <unordered_map>

namespace timescend::core {

class ActionDispatcher {
public:
    using Action = std::function<void()>;

    void registerAction(const std::string& name, Action action);
    bool dispatch(const std::string& name) const;

private:
    std::unordered_map<std::string, Action> actions_{};
};

} // namespace timescend::core
