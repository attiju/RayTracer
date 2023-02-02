#include <gauss.hpp>

inline Float gaussian(Float x, Float l, Float m)
{
    return std::max(Float(0), Float(std::exp(-l * x * x) - m));
}

Float Gauss::operator()(const Point2f &p) const
{
    return gaussian(p.x, lambda, exp_x) * gaussian(p.y, lambda, exp_y);
}