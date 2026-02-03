#pragma once

namespace timescend::system {

class PowerManager {
public:
    void lockWorkstation() const;
    void sleepSystem() const;
    void shutdownSystem() const;
};

} // namespace timescend::system
