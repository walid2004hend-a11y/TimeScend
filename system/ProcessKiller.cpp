#include "ProcessKiller.hpp"

namespace timescend::system {

bool ProcessKiller::terminateProcess(const std::string& processName) const {
    (void)processName;
    return false;
}

} // namespace timescend::system
