#include <sphere.hpp>

bool Sphere::intersects(const Ray &ray, Interaction *intr) {
    const Ray r = (*world_to_object)(ray);

    const Float a = dot(r.d, r.d);
    const Float b = 2 * dot(r.d, Vector3f(r.o));
    const Float c = dot(Vector3f(r.o), Vector3f(r.o)) - radius * radius;

    Float t0, t1;

    bool hit = solve_quadratic(a, b, c, &t0, &t1);

    if (t0 < r.t && t0 > 0) r.t = t0;
    else if (t1 < r.t && t1 > 0) r.t = t1;

    *intr = Interaction(r(), -r.d, Normal3f(normalize(Vector3f(r()))));

    return hit;
}

bool Sphere::intersects(const Ray &ray) {
    const Ray r = (*world_to_object)(ray);

    const Float a = dot(r.d, r.d);
    const Float b = 2 * dot(r.d, Vector3f(r.o));
    const Float c = dot(Vector3f(r.o), Vector3f(r.o)) - radius * radius;

    Float t0, t1;

    bool hit = solve_quadratic(a, b, c, &t0, &t1);

    return hit;
}
