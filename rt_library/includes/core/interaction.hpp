#ifndef INTERACTION_HH
#define INTERACTION_HH

#include <core.hpp>

#include "point_3.hpp"
#include "vector_3.hpp"
#include "normal_3.hpp"

class Interaction {
public:
    inline Interaction();

    inline Interaction(const Point3f &p, const Vector3f &wo, const Normal3f &n);

public:
    Point3f  p;
    Vector3f wo;
    Normal3f n;
};

#include <interaction.inl>

#endif