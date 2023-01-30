#include "transform.hpp"

Transform::Transform()
        : m(Matrix4x4()), m_inv(Matrix4x4())
{

}

Transform::Transform(const Matrix4x4 &m)
        : m(m), m_inv(inverse(m))
{

}

Transform::Transform(const Matrix4x4 &m, const Matrix4x4 &m_inv)
        : m(m), m_inv(m_inv)
{

}

Transform Transform::operator*(const Transform &T) const
{
    return Transform(m * T.m, T.m_inv * m_inv);
}

template<typename T>
Point3<T> Transform::operator()(const Point3<T> &p) const
{
    T x = p.x, y = p.y, z = p.z;
    T xp = m.m[0][0] * x + m.m[0][1] * y + m.m[0][2] * z + m.m[0][3];
    T yp = m.m[1][0] * x + m.m[1][1] * y + m.m[1][2] * z + m.m[1][3];
    T zp = m.m[2][0] * x + m.m[2][1] * y + m.m[2][2] * z + m.m[2][3];
    T wp = m.m[3][0] * x + m.m[3][1] * y + m.m[3][2] * z + m.m[3][3];

    if (wp == 1)
        return Point3<T>(xp, yp, zp);
    else
        return Point3<T>(xp, yp, zp) / wp;
}

template<typename T>
Vector3<T> Transform::operator()(const Vector3<T> &v) const
{
    T x = v.x, y = v.y, z = v.z;
    T xp = m.m[0][0] * x + m.m[0][1] * y + m.m[0][2] * z;
    T yp = m.m[1][0] * x + m.m[1][1] * y + m.m[1][2] * z;
    T zp = m.m[2][0] * x + m.m[2][1] * y + m.m[2][2] * z;

    return Vector3<T>(xp, yp, zp);
}

template<typename T>
Normal3<T> Transform::operator()(const Normal3<T> &n) const
{
    T x = n.x, y = n.y, z = n.z;
    T xp = m_inv.m[0][0] * x + m_inv.m[1][0] * y + m_inv.m[2][0] * z;
    T yp = m_inv.m[0][1] * x + m_inv.m[1][1] * y + m_inv.m[2][1] * z;
    T zp = m_inv.m[0][2] * x + m_inv.m[1][2] * y + m_inv.m[2][2] * z;

    return Normal3<T>(xp, yp, zp);
}

bool Transform::operator==(const Transform &T) const
{
    return m == T.m && m_inv == T.m_inv;
}

Ray Transform::operator()(const Ray &r) const
{
    auto T = *this;
    return Ray(T(r.o), T(r.d), r.t);
}

SurfaceInteraction Transform::operator()(const SurfaceInteraction &interaction) const
{
    auto T = *this;

    return SurfaceInteraction(
            T(interaction.p),
            T(interaction.wo),
            T(interaction.n),
            interaction.uv
    );
}

inline Transform inverse(const Transform &T)
{
    return Transform(T.m_inv, T.m);
}

inline Transform transpose(const Transform &T)
{
    return Transform(transpose(T.m), transpose(T.m_inv));
}

Transform translate(const Vector3f &v)
{
    Matrix4x4 m(1, 0, 0, v.x, 0, 1, 0, v.y, 0, 0, 1, v.z, 0, 0, 0, 1);
    Matrix4x4 m_inv(1, 0, 0, -v.x, 0, 1, 0, -v.y, 0, 0, 1, -v.z, 0, 0, 0, 1);

    return Transform(m, m_inv);
}

Transform scale(Float x, Float y, Float z)
{
    Matrix4x4 m(x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1);
    Matrix4x4 m_inv(1 / x, 0, 0, 0, 0, 1 / y, 0, 0, 0, 0, 1 / z, 0, 0, 0, 0, 1);

    return Transform(m, m_inv);
}

Transform rotateX(Float theta)
{
    Float sinTheta = std::sin(radians(theta));
    Float cosTheta = std::cos(radians(theta));

    Matrix4x4 m(1, 0, 0, 0, 0, cosTheta, -sinTheta, 0, 0, sinTheta, cosTheta, 0, 0, 0, 0, 1);

    return Transform(m, transpose(m));
}

Transform rotateY(Float theta)
{
    Float sinTheta = std::sin(radians(theta));
    Float cosTheta = std::cos(radians(theta));

    Matrix4x4 m(cosTheta, 0, sinTheta, 0, 0, 1, 0, 0, -sinTheta, 0, cosTheta, 0, 0, 0, 0, 1);

    return Transform(m, transpose(m));
}

Transform rotateZ(Float theta)
{
    Float sinTheta = std::sin(radians(theta));
    Float cosTheta = std::cos(radians(theta));

    Matrix4x4 m(cosTheta, -sinTheta, 0, 0, sinTheta, cosTheta, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    return Transform(m, transpose(m));
}