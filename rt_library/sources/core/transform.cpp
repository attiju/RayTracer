#include <transform.hpp>

std::ostream &operator<<(std::ostream &os, const Transform &T) {
    return os << "{ m = " << T.m << " m_inv = " << T.m_inv << " }";
}
