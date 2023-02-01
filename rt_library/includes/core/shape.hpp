#ifndef SHAPE_HH
#define SHAPE_HH

#include <core.hpp>
#include <transform.hpp>
#include <surface_interaction.hpp>

class Shape {
public:
    inline Shape(const Transform *object_to_world, const Transform *world_to_object);

    inline virtual ~Shape();

public:
    virtual bool intersects(const Ray &ray, Float* t_hit, SurfaceInteraction *interaction) = 0;

    virtual bool intersects(const Ray &ray) = 0;

public:
    const Transform *object_to_world;
    const Transform *world_to_object;

};

#include <shape.inl>

#endif