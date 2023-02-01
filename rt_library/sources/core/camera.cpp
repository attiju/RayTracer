#include <camera.hpp>

Ray Camera::next_ray(const CameraSample &sample) const {
    Point3f film_point   = Point3f(sample.film_point.x, sample.film_point.y, 0);
    Point3f camera_point = raster_to_camera(film_point);

    const Ray camera_space_ray = Ray({0, 0, 0}, normalize(Vector3f(camera_point)));
    return camera_to_world(camera_space_ray);
}
