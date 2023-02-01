#ifndef BOUNDS_2_HH
#define BOUNDS_2_HH

#include <core.hpp>

template<typename T>
class Bounds2 {
public:
    inline Bounds2();

    inline explicit Bounds2(const Point2<T> &p);

    inline Bounds2(const Point2<T> &a, const Point2<T> &b);

public:
    Point2<T> p_min;
    Point2<T> p_max;

};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Bounds2<T> &bounds2);

#include <bounds_2.inl>

#endif