#include <spectrum.hpp>

std::ostream &operator<<(std::ostream &os, const Spectrum &spectrum) {
    return os << "{ x: " << spectrum.x << " y: " << spectrum.y << " z: " << spectrum.z << " }";
}
