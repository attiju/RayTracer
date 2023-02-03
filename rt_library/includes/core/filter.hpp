#ifndef FILTER_HH
#define FILTER_HH

#include <core.hpp>
#include <point_2.hpp>
#include <vector_2.hpp>

class Filter {
 public:
  inline Filter(const Vector2f &size);

  inline virtual ~Filter() = default;

 public:
  virtual Float operator()(const Point2f &p) const = 0;

 public:
  const Vector2f size;
  const Vector2f inv_size;
};

#include <filter.inl>

#endif