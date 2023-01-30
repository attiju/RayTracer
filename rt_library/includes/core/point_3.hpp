#ifndef POINT_3_HH
#define POINT_3_HH

#include <core.hpp>

template<typename T>
class Point3 {
public:
    inline Point3();

    inline Point3(T x, T y, T z);

    template<typename U>
    inline explicit Point3(const Point3<U> &p);

    template<typename U>
    inline explicit Point3(const Vector3<U> &v);

public:
    inline Point3<T> operator-() const;

    inline Point3<T> operator+(const Vector3<T> &v) const;

    inline Vector3<T> operator-(const Point3<T> &v) const;

    inline Point3<T> operator*(Float f) const;

    inline Point3<T> operator/(Float s) const;

    inline Point3<T> &operator*=(Float f);

    inline Point3<T> &operator/=(Float s);

public:
    inline bool operator==(const Point3<T> &v) const;

public:
    T x, y, z;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Point3<T> &p);

template<typename T>
Point3<T> operator*(Float f, const Point3<T> &v);

template<typename T>
inline T distance_squared(const Point3<T> &a, const Point3<T> &b);

template<typename T>
inline Float distance(const Point3<T> &a, const Point3<T> &b);

typedef Point3<int>   Point3i;
typedef Point3<Float> Point3f;

#include <point_3.inl>

#endif