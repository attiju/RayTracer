#ifndef NORMAL_3_HH
#define NORMAL_3_HH

#include <core/core.hpp>

template<typename T>
class Normal3 {
public:
    inline Normal3();

    inline Normal3(T x, T y, T z);

    template<typename U>
    inline explicit Normal3(const Normal3<U> &n);

    template<typename U>
    inline explicit Normal3(const Vector3<U> &v);

    template<typename U>
    inline explicit Normal3(const Point3<U> &p);

public:
    inline Normal3<T> operator-() const;

    inline Normal3<T> operator+(const Normal3<T> &v) const;

    inline Normal3<T> operator-(const Normal3<T> &v) const;

    inline Normal3<T> operator*(Float f) const;

    inline Normal3<T> operator/(Float s) const;

    inline Normal3<T> &operator+=(const Normal3<T> &v);

    inline Normal3<T> &operator-=(const Normal3<T> &v);

    inline Normal3<T> &operator*=(Float f);

    inline Normal3<T> &operator/=(Float s);

public:
    inline bool operator==(const Normal3<T> &v) const;

public:
    T x, y, z;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Normal3<T> &n);

template<typename T>
Normal3<T> operator*(Float f, const Normal3<T> &v);

typedef Normal3<int> Normal3i;
typedef Normal3<Float> Normal3f;

#include <core/normal_3.inl>

#endif