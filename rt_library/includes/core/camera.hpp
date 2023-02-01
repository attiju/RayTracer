#ifndef CAMERA_HH
#define CAMERA_HH

#include <core.hpp>
#include <ray.hpp>
#include <camera_sample.hpp>
#include <transform.hpp>

class Camera {
public:
    inline Camera(const Transform *camera_to_world, const Film *film, Float lens_radius, Float focal_distance, Float field_of_view);

public:
    Ray next_ray(const CameraSample &sample) const;

public:
    const Transform *camera_to_world;
    const Film *film;
    const Float lens_radius;
    const Float focal_distance;
    const Float field_of_view;

private:
    Vector3f dx;
    Vector3f dy;
    Float    A;

};

#include <camera.inl>

#endif