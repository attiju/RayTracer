Camera::Camera(
        const Transform *camera_to_world,
        const Film *film,
        Float lens_radius,
        Float focal_distance,
        Float field_of_view
)
        : camera_to_world(camera_to_world),
          film(film),
          lens_radius(lens_radius),
          focal_distance(focal_distance),
          field_of_view(field_of_view)
{

}