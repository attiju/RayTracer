#ifndef FILM_TILE_HH
#define FILM_TILE_HH

#include <core.hpp>
#include <point_2.hpp>
#include <bounds_2.hpp>
#include <vector_2.hpp>
#include <film_pixel.hpp>

class FilmTile {
public:
    inline FilmTile(const Bounds2i &bounds,
                    const Vector2f &filterSize,
                    const Vector2f &filterInvSize,
                    const Float *filterTable,
                    const int filterTableSize);

public:

    void add_sample(const Point2f &p, const Spectrum &value);

public:
    const Bounds2i         bounds;
    const Vector2f         filter_size;
    const Vector2f         filter_inv_size;
    const Float            *filterTable;
    const int              filterTableSize;
    std::vector<FilmPixel> pixels;

};

#include <film_tile.inl>

#endif