#ifndef FILM_HH
#define FILM_HH

#include <core.hpp>
#include <point_2.hpp>

class Film {
public:
    inline Film(const Point2i &resolution, Float diagonal);

public:
    const Point2i resolution;
    const Float   diagonal;

};

#include <film.inl>

#endif