#include <camera.hpp>

Ray Camera::next_ray(const CameraSample &sample) const
{
    const Float w = 512;
    const Float h = 512;

    const Ray camera_space_ray = Ray(
            {0, 0, 0},
            normalize(Vector3f(
                    sample.film_point.x - w * 0.5,
                    h * 0.5 - sample.film_point.y,
                    -400
            ))
    );

    return (*camera_to_world)(camera_space_ray);
}
