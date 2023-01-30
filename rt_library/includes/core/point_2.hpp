#ifndef POINT_2_HH
#define POINT_2_HH

#include <core/core.hpp>

template<typename T>
class Point2 {
public:
    inline Point2();

    inline Point2(T x, T y);

    template<typename U>
    inline explicit Point2(const Point2<U> &p);

    template<typename U>
    inline explicit Point2(const Vector2<U> &v);

public:
    inline Point2<T> operator-() const;

    inline Point2<T> operator+(const Vector2<T> &v) const;

    inline Vector2<T> operator-(const Point2<T> &v) const;

    inline Point2<T> operator*(Float f) const;

    inline Point2<T> operator/(Float s) const;

    inline Point2<T> &operator*=(Float f);

    inline Point2<T> &operator/=(Float s);

public:
    inline bool operator==(const Point2<T> &v) const;

public:
    T x, y;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Point2<T> &p);

template<typename T>
Point2<T> operator*(Float f, const Point2<T> &v);

typedef Point2<int> Point2i;
typedef Point2<Float> Point2f;

#include <core/point_2.inl>

#endif