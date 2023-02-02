#ifndef CAMERA_HH
#define CAMERA_HH

#include <core.hpp>
#include <ray.hpp>
#include <bounds_2.hpp>
#include <camera_sample.hpp>
#include <transform.hpp>
#include <film.hpp>

class Camera {
public:
    inline Camera(const Transform &camera_to_world, Film *film, Float lens_radius, Float focal_distance,
                  Float field_of_view);

public:
    Ray next_ray(const CameraSample &sample) const;

public:
    Transform camera_to_world;
    Transform raster_to_camera;
    Film      *film;
    Float     lens_radius;
    Float     focal_distance;

};

#include <camera.inl>

#endif