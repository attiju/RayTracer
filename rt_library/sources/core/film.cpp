#include <film.hpp>

Bounds2f Film::world_film_size() const {
    Float aspect = Float(resolution.y) / Float(resolution.x);
    Float x      = std::sqrt(diagonal * diagonal / (1 + aspect * aspect));
    Float y      = aspect * x;

    return {{-x / 2, -y / 2}, {x / 2,  y / 2}};
}

FilmPixel &Film::operator[](const Point2i &p) {
    return pixels[(p.x - pixel_bounds.p_min.x) +
                  (p.y - pixel_bounds.p_min.y) * (pixel_bounds.p_max.x - pixel_bounds.p_min.x)];
}
