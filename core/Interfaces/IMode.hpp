#pragma once

namespace timescend::core {

class IMode {
public:
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void update() = 0;
    virtual ~IMode() = default;
};

} // namespace timescend::core
