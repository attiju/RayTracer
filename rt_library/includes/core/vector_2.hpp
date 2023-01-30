#ifndef VECTOR_2_HH
#define VECTOR_2_HH

#include <core.hpp>

template<typename T>
class Vector2 {
public:
    inline Vector2();

    inline Vector2(T x, T y);

    template<typename U>
    inline explicit Vector2(const Vector2<U> &v);

    template<typename U>
    inline explicit Vector2(const Point2<U> &p);

public:
    inline Vector2<T> operator-() const;

    inline Vector2<T> operator+(const Vector2<T> &v) const;

    inline Vector2<T> operator-(const Vector2<T> &v) const;

    inline Vector2<T> operator*(Float f) const;

    inline Vector2<T> operator/(Float s) const;

    inline Vector2<T> &operator+=(const Vector2<T> &v);

    inline Vector2<T> &operator-=(const Vector2<T> &v);

    inline Vector2<T> &operator*=(Float f);

    inline Vector2<T> &operator/=(Float s);

public:
    inline bool operator==(const Vector2<T> &v) const;

public:
    T x, y;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector2<T> &v);

template<typename T>
Vector2<T> operator*(Float f, const Vector2<T> &v);

typedef Vector2<int>   Vector2i;
typedef Vector2<Float> Vector2f;

#include <vector_2.inl>

#endif