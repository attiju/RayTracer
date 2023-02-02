FilmTile::FilmTile(const Bounds2i &bounds,
                   const Vector2f &filterSize,
                   const Vector2f &filterInvSize,
                   const Float *filterTable,
                   const int filterTableSize)
        : bounds(bounds),
          filter_size(filterSize),
          filter_inv_size(filterInvSize),
          filterTable(filterTable),
          filterTableSize(filterTableSize),
          pixels(std::vector<FilmPixel>(std::max(0, bounds.area())))
{

}