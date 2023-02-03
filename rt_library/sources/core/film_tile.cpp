#include <film_tile.hpp>

void FilmTile::add_sample(const Point2f &p, const Spectrum &value, Float weight) {
  Point2f shifted_p = p - Vector2f(0.5f, 0.5f);
  Point2i p0 = Point2i(ceil(shifted_p - filter_size));
  Point2i p1 = Point2i(floor(shifted_p + filter_size)) + Vector2i(1, 1);
  p0 = max(p0, bounds.p_min);
  p1 = min(p1, bounds.p_max);

  int *ifx = (int *) alloca(p1.x - p0.x);
  for (int x = p0.x;
       x < p1.x;
       ++x) {
    Float fx = std::abs((x - shifted_p.x) * filter_inv_size.x *
        filter_table_size);
    ifx[x - p0.x] = std::min((int) std::floor(fx), filter_table_size - 1);
  }
  int *ify = (int *) alloca(p1.y - p0.y);
  for (int y = p0.y;
       y < p1.y;
       ++y) {
    Float fy = std::abs((y - shifted_p.y) * filter_inv_size.y *
        filter_table_size);
    ify[y - p0.y] = std::min((int) std::floor(fy), filter_table_size - 1);
  }
  for (int y = p0.y;
       y < p1.y;
       ++y) {
    for (int x = p0.x;
         x < p1.x;
         ++x) {
      int offset = ify[y - p0.y] * filter_table_size + ifx[x - p0.x];
      Float filterWeight = filter_table[offset];

      FilmPixel &pixel = this->operator[](Point2i(x, y));
      pixel.color += value * weight * filterWeight;
      pixel.weight_sum += filterWeight;
    }
  }
}

FilmPixel &FilmTile::operator[](const Point2i &p) {
  return pixels[(p.x - bounds.p_min.x) + (p.y - bounds.p_min.y) * (bounds.p_max.x - bounds.p_min.x)];
}
