Shape::Shape(const Transform *object_to_world, const Transform *world_to_object)
        : object_to_world(object_to_world), world_to_object(world_to_object) {
}

Shape::~Shape() = default;
