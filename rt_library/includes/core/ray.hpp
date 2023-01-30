#ifndef RAY_HH
#define RAY_HH

#include <core/core.hpp>
#include <core/point_3.hpp>
#include <core/vector_3.hpp>

class Ray {
public:
    inline Ray();

    inline Ray(const Point3f &o, const Vector3f &d);

    inline Ray(const Point3f &o, const Vector3f &d, Float t);

public:

    inline Point3f operator()() const;

public:
    Point3f o;
    Vector3f d;
    Float t;
};

std::ostream &operator<<(std::ostream &os, const Ray &r);

#include <core/ray.inl>

#endif