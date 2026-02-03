#pragma once

#include <string>

namespace timescend::system {

class WindowController {
public:
    bool focusWindow(const std::string& title) const;
};

} // namespace timescend::system
