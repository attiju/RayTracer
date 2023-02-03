#ifndef GAUSS_HH
#define GAUSS_HH

#include <filter.hpp>

class Gauss :
    public Filter {
 public:
  inline Gauss(const Vector2f &size, Float lambda);

 public:
  Float operator()(const Point2f &p) const override;

 private:
  const Float lambda;
  const Float exp_x, exp_y;
};

#include <gauss.inl>

#endif