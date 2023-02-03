#ifndef FILM_HH
#define FILM_HH

#include <core.hpp>
#include <point_2.hpp>
#include <bounds_2.hpp>
#include <film_pixel.hpp>
#include <film_tile.hpp>
#include <filter.hpp>

#define FILTER_TABLE_SIZE 16

class Film {
 public:
  inline Film(const Point2i &resolution, std::unique_ptr<Filter> filter, Float diagonal);

 public:
  Bounds2f world_film_size() const;

  FilmPixel &operator[](const Point2i &pixel);

  std::unique_ptr<FilmTile> operator[](const Bounds2i &sample_bounds) const;

  void merge(std::unique_ptr<FilmTile> tile);

 public:
  const Point2i resolution;
  const Float diagonal;
  const Bounds2i pixel_bounds;
  std::unique_ptr<Filter> filter;

 private:
  Float table[FILTER_TABLE_SIZE * FILTER_TABLE_SIZE];
  std::unique_ptr<FilmPixel[]> pixels;
  std::mutex mutex;
};

#include <film.inl>

#endif