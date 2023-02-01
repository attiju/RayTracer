#ifndef RAY_HH
#define RAY_HH

#include <core.hpp>
#include <point_3.hpp>
#include <vector_3.hpp>

class Ray {
public:
    inline Ray();

    inline Ray(const Point3f &o, const Vector3f &d);

    inline Ray(const Point3f &o, const Vector3f &d, Float t);

public:

    inline Point3f operator()() const;

    inline Point3f operator()(Float dt) const;

public:
    Point3f       o;
    Vector3f      d;
    mutable Float t;
};

std::ostream &operator<<(std::ostream &os, const Ray &r);

#include <ray.inl>

#endif