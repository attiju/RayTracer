#include <sphere.hpp>

bool Sphere::intersects(const Ray &ray, Float *t_hit, SurfaceInteraction *interaction) {
  const Ray r = (*world_to_object)(ray);

  const Float a = dot(r.d, r.d);
  const Float b = 2 * dot(r.d, Vector3f(r.o));
  const Float c = dot(Vector3f(r.o), Vector3f(r.o)) - radius * radius;

  Float t0, t1;
  if (!solve_quadratic(a, b, c, &t0, &t1)) {
    return false;
  }

  if (t0 > r.t || t1 < 0) { return false; }

  Float tShapeHit = t0;
  if (tShapeHit <= 0) {
    tShapeHit = t1;
    if (tShapeHit > ray.t) {
      return false;
    }
  }

  Point3f pHit = r(tShapeHit);

  SurfaceInteraction object_space_interaction = SurfaceInteraction(
      pHit,
      -r.d,
      normalize(Normal3f(pHit)),
      Point2f()
  );

  *interaction = (*object_to_world)(object_space_interaction);
  *t_hit = tShapeHit;

  return true;
}

bool Sphere::intersects(const Ray &ray) {
  const Ray r = (*world_to_object)(ray);

  const Float a = dot(r.d, r.d);
  const Float b = 2 * dot(r.d, Vector3f(r.o));
  const Float c = dot(Vector3f(r.o), Vector3f(r.o)) - radius * radius;

  Float t0, t1;
  if (!solve_quadratic(a, b, c, &t0, &t1)) {
    return false;
  }

  if (t0 > r.t || t1 < 0) { return false; }

  Float tShapeHit = t0;
  if (tShapeHit <= 0) {
    tShapeHit = t1;
    if (tShapeHit > ray.t) {
      return false;
    }
  }

  return true;
}
