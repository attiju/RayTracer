Film::Film(const Point2i &resolution, Float diagonal)
        : resolution(resolution),
          diagonal(diagonal * 1e-3),
          pixel_bounds(Bounds2i({0, 0}, resolution)),
          pixels(std::unique_ptr<FilmPixel[]>(new FilmPixel[pixel_bounds.area()])) {

}