#ifndef VECTOR_3_HH
#define VECTOR_3_HH

#include <core.hpp>

template<typename T>
class Vector3 {
public:
    inline Vector3();

    inline Vector3(T x, T y, T z);

    template<typename U>
    inline explicit Vector3(const Vector3<U> &v);

    template<typename U>
    inline explicit Vector3(const Point3<U> &p);

    template<typename U>
    inline explicit Vector3(const Normal3<U> &n);

public:
    inline Vector3<T> operator-() const;

    inline Vector3<T> operator+(const Vector3<T> &v) const;

    inline Vector3<T> operator-(const Vector3<T> &v) const;

    inline Vector3<T> operator*(Float f) const;

    inline Vector3<T> operator/(Float s) const;

    inline Vector3<T> &operator+=(const Vector3<T> &v);

    inline Vector3<T> &operator-=(const Vector3<T> &v);

    inline Vector3<T> &operator*=(Float f);

    inline Vector3<T> &operator/=(Float s);

public:
    inline bool operator==(const Vector3<T> &v) const;

public:
    T x, y, z;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3<T> &v);

template<typename T>
inline Vector3<T> operator*(Float f, const Vector3<T> &v);

template<typename T>
inline Vector3<T> abs(const Vector3<T> &a);

template<typename T>
inline T dot(const Vector3<T> &a, const Vector3<T> &b);

template<typename T>
inline Vector3<T> cross(const Vector3<T> &a, const Vector3<T> &b);

template<typename T>
inline T length_squared(const Vector3<T> &a);

template<typename T>
inline T length(const Vector3<T> &a);

template<typename T>
inline Vector3<T> normalize(const Vector3<T> &a);

typedef Vector3<int>   Vector3i;
typedef Vector3<Float> Vector3f;

#include <vector_3.inl>

#endif