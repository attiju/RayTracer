#include <ray.hpp>

std::ostream &operator<<(std::ostream &os, const Ray &r) {
    return os << "{ o=" << r.o << " d=" << r.d << " t=" << r.t << " }";
}
