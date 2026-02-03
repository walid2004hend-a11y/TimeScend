#pragma once

#include <string>

namespace timescend::config {

class Config {
public:
    std::string dataDirectory() const;
};

} // namespace timescend::config
