#ifndef FILM_HH
#define FILM_HH

#include <core.hpp>
#include <point_2.hpp>
#include <bounds_2.hpp>
#include <film_pixel.hpp>

class Film {
public:
    inline Film(const Point2i &resolution, Float diagonal);

public:
    Bounds2f world_film_size() const;

    FilmPixel& operator[](const Point2i& p);

public:
    const Point2i  resolution;
    const Float    diagonal;
    const Bounds2i pixel_bounds;

private:
    std::unique_ptr<FilmPixel[]> pixels;

};

#include <film.inl>

#endif