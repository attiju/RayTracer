Camera::Camera(
    const Transform &camera_to_world,
    Film *film,
    Float lens_radius,
    Float focal_distance,
    Float field_of_view
)
    : camera_to_world(camera_to_world),
      raster_to_camera(),
      film(film),
      lens_radius(lens_radius),
      focal_distance(focal_distance) {
  const Float aspect_ratio = Float(film->resolution.x) / Float(film->resolution.y);

  Bounds2f screen;

  if (aspect_ratio > 1) {
    screen.p_min.x = -aspect_ratio;
    screen.p_max.x = aspect_ratio;
    screen.p_min.y = -1.f;
    screen.p_max.y = 1.f;
  } else {
    screen.p_min.x = -1.f;
    screen.p_max.x = 1.f;
    screen.p_min.y = -1.f / aspect_ratio;
    screen.p_max.y = 1.f / aspect_ratio;
  }

  raster_to_camera = scale(1, 1, -1)
      * inverse(perspective(field_of_view, 1e-2, 1000.))
      * inverse(scale(film->resolution.x / (screen.p_max.x - screen.p_min.x),
                      film->resolution.y / (screen.p_min.y - screen.p_max.y),
                      1) * translate({-screen.p_min.x, -screen.p_max.y, 0}));
}