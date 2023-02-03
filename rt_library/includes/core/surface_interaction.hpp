#ifndef SURFACE_INTERACTION_HH
#define SURFACE_INTERACTION_HH

#include <core.hpp>
#include <interaction.hpp>

class SurfaceInteraction :
    public Interaction {
 public:
  inline SurfaceInteraction();

  inline SurfaceInteraction(const Point3f &p, const Vector3f &wo, const Normal3f &n, const Point2f &uv);

 public:
  Point2f uv;
};

#include <surface_interaction.inl>

#endif