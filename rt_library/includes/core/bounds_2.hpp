#ifndef BOUNDS_2_HH
#define BOUNDS_2_HH

#include <core.hpp>
#include <point_2.hpp>
#include <vector_2.hpp>

template<typename T>
class Bounds2 {
 public:
  inline Bounds2();

  template<typename U>
  inline explicit Bounds2(const Bounds2<U> &b);

  inline explicit Bounds2(const Point2<T> &p);

  inline Bounds2(const Point2<T> &a, const Point2<T> &b);

 public:
  inline Vector2<T> diagonal() const;

  inline T area() const;

 public:
  Point2<T> p_min;
  Point2<T> p_max;

};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Bounds2<T> &bounds2);

template<typename T>
Bounds2<T> intersect(const Bounds2<T> &b1, const Bounds2<T> &b2);

typedef Bounds2<int> Bounds2i;

typedef Bounds2<Float> Bounds2f;

class Bounds2iIterator :
    public std::forward_iterator_tag {
 public:
  Bounds2iIterator(const Bounds2i &b, const Point2i &pt)
      : p(pt), bounds(&b) {}

  Bounds2iIterator operator++() {
    advance();
    return *this;
  }

  Bounds2iIterator operator++(int) {
    Bounds2iIterator old = *this;
    advance();
    return old;
  }

  bool operator==(const Bounds2iIterator &bi) const {
    return p == bi.p && bounds == bi.bounds;
  }

  bool operator!=(const Bounds2iIterator &bi) const {
    return p != bi.p || bounds != bi.bounds;
  }

  Point2i operator*() const { return p; }

 private:
  void advance() {
    ++p.x;
    if (p.x == bounds->p_max.x) {
      p.x = bounds->p_min.x;
      ++p.y;
    }
  }

  Point2i p;
  const Bounds2i *bounds;
};

inline Bounds2iIterator begin(const Bounds2i &b) {
  return Bounds2iIterator(b, b.p_min);
}

inline Bounds2iIterator end(const Bounds2i &b) {
  Point2i pEnd(b.p_min.x, b.p_max.y);
  if (b.p_min.x >= b.p_max.x || b.p_min.y >= b.p_max.y) {
    pEnd = b.p_min;
  }
  return Bounds2iIterator(b, pEnd);
}

#include <bounds_2.inl>

#endif