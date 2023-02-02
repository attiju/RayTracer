#include <film.hpp>

Bounds2f Film::world_film_size() const
{
    Float aspect = Float(resolution.y) / Float(resolution.x);
    Float x      = std::sqrt(diagonal * diagonal / (1 + aspect * aspect));
    Float y      = aspect * x;

    return {{-x / 2, -y / 2}, {x / 2, y / 2}};
}

FilmPixel &Film::operator[](const Point2i &pixel)
{
    return pixels[(pixel.x - pixel_bounds.p_min.x) + (pixel.y - pixel_bounds.p_min.y) * (pixel_bounds.p_max.x - pixel_bounds.p_min.x)];
}

std::unique_ptr<FilmTile> Film::operator[](const Bounds2i &sample_bounds) const
{
    Vector2f half        = Vector2f(0.5f, 0.5f);
    Bounds2f floatBounds = Bounds2f(sample_bounds);
    Point2i  p0          = Point2i(ceil(floatBounds.p_min - half - filter->size));
    Point2i  p1          = Point2i(floor(floatBounds.p_max - half + filter->size)) + Vector2i(1, 1);
    Bounds2i tile_bounds = intersect(Bounds2i(p0, p1), pixel_bounds);

    return std::unique_ptr<FilmTile>(
            new FilmTile(tile_bounds,
                         filter->size,
                         filter->inv_size,
                         table,
                         FILTER_TABLE_SIZE)
    );
}

void Film::merge(std::unique_ptr<FilmTile> tile)
{
    std::lock_guard<std::mutex> lock(mutex);

    // TODO merge tile
}
