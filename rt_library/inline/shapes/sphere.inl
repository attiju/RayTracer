
Sphere::Sphere(const Transform *object_to_world, const Transform *world_to_object, Float radius)
    : Shape(object_to_world, world_to_object), radius(radius) {
}
