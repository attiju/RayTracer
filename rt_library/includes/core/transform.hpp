#ifndef TRANSFORM_HH
#define TRANSFORM_HH

#include <point_3.hpp>
#include <vector_3.hpp>
#include <normal_3.hpp>
#include <ray.hpp>
#include <matrix_4_4.hpp>

class Transform {
public:
    inline Transform();

    inline explicit Transform(const Matrix4x4 &m);

    inline Transform(const Matrix4x4 &m, const Matrix4x4 &m_inv);

public:
    inline Transform operator*(const Transform &T) const;

    template<typename T>
    inline Point3<T> operator()(const Point3<T> &p) const;

    template<typename T>
    inline Vector3<T> operator()(const Vector3<T> &v) const;

    template<typename T>
    inline Normal3<T> operator()(const Normal3<T> &n) const;

    inline Ray operator()(const Ray &r) const;

public:
    inline bool operator==(const Transform &T) const;

public:
    Matrix4x4 m, m_inv;
};

std::ostream &operator<<(std::ostream &os, const Transform &T);

inline Transform inverse(const Transform &T);

inline Transform transpose(const Transform &T);

inline Transform translate(const Vector3f &v);

inline Transform scale(Float x, Float y, Float z);

inline Transform rotateX(Float theta);

inline Transform rotateY(Float theta);

inline Transform rotateZ(Float theta);

#include <transform.inl>

#endif