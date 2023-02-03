Film::Film(const Point2i &resolution, std::unique_ptr<Filter> filter, Float diagonal)
    : resolution(resolution),
      diagonal(diagonal * 1e-3),
      pixel_bounds(Bounds2i({}, resolution)),
      filter(std::move(filter)),
      pixels(std::unique_ptr<FilmPixel[]>(new FilmPixel[pixel_bounds.area()])) {
  int offset = 0;
  for (int y = 0;
       y < FILTER_TABLE_SIZE;
       ++y) {
    for (int x = 0;
         x < FILTER_TABLE_SIZE;
         ++x, ++offset) {
      table[offset] = (*this->filter)(Point2f((x + 0.5f) * this->filter->size.x,
                                              (y + 0.5f) * this->filter->size.y) / FILTER_TABLE_SIZE);
    }
  }
}