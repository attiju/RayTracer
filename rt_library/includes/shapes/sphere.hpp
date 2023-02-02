#ifndef SPHERE_HH
#define SPHERE_HH

#include <shape.hpp>

class Sphere : public Shape {
public:
    inline Sphere(const Transform *object_to_world, const Transform *world_to_object, Float radius);

public:
    bool intersects(const Ray &ray, Float *t_hit, SurfaceInteraction *interaction) override;

    bool intersects(const Ray &ray) override;

public:
    Float radius;

};

#include <sphere.inl>

#endif