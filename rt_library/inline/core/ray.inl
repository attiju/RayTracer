
#include "ray.hpp"

Ray::Ray()
        : o(Point3f()), d(Vector3f(0, 0, -1)), t(inf)
{

}

Ray::Ray(const Point3f &o, const Vector3f &d)
        : o(o), d(d), t(inf)
{

}

Ray::Ray(const Point3f &o, const Vector3f &d, Float t)
        : o(o), d(d), t(t)
{

}

Point3f Ray::operator()() const
{
    return o + t * d;
}

Point3f Ray::operator()(Float dt) const
{
    return o + dt * d;
}
