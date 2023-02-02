#include <timer.hpp>

long long Timer::elapsed_time() const {
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}
