template<typename T>
Normal3<T>::Normal3()
        : x(0), y(0), z(0)
{

}

template<typename T>
Normal3<T>::Normal3(T x, T y, T z)
        : x(x), y(y), z(z)
{

}

template<typename T>
template<typename U>
Normal3<T>::Normal3(const Normal3<U> &n)
        : x(T(n.x)), y(T(n.y)), z(T(n.z))
{

}

template<typename T>
template<typename U>
Normal3<T>::Normal3(const Vector3<U> &v)
        : x(T(v.x)), y(T(v.y)), z(T(v.z))
{

}

template<typename T>
template<typename U>
Normal3<T>::Normal3(const Point3<U> &p)
        : x(T(p.x)), y(T(p.y)), z(T(p.z))
{

}

template<typename T>
Normal3<T> Normal3<T>::operator-() const
{
    return Normal3<T>(-x, -y, -z);
}

template<typename T>
Normal3<T> Normal3<T>::operator+(const Normal3<T> &v) const
{
    return Normal3<T>(x + v.x, y + v.y, z + v.z);
}

template<typename T>
Normal3<T> Normal3<T>::operator-(const Normal3<T> &v) const
{
    return Normal3<T>(x - v.x, y - v.y, z - v.z);
}

template<typename T>
Normal3<T> Normal3<T>::operator*(Float f) const
{
    return Normal3<T>(x * f, y * f, z * f);
}

template<typename T>
Normal3<T> Normal3<T>::operator/(Float s) const
{
    Float f = Float(1) / s;
    return Normal3<T>(x * f, y * f, z * f);
}

template<typename T>
Normal3<T> &Normal3<T>::operator+=(const Normal3<T> &v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

template<typename T>
Normal3<T> &Normal3<T>::operator-=(const Normal3<T> &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

template<typename T>
Normal3<T> &Normal3<T>::operator*=(Float f)
{
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
Normal3<T> &Normal3<T>::operator/=(Float s)
{
    Float f = Float(1) / s;
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
bool Normal3<T>::operator==(const Normal3<T> &v) const
{
    return x == v.x && y == v.y && z == v.z;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Normal3<T> &n)
{
    return os << "{ " << n.x << " " << n.y << " " << n.z << " }";
}

template<typename T>
Normal3<T> operator*(Float f, const Normal3<T> &v)
{
    return v * f;
}


template<typename T>
inline Normal3<T> abs(const Normal3<T> &a)
{
    return Normal3<T>(std::abs(a.x), std::abs(a.y), std::abs(a.z));
}

template<typename T>
T dot(const Normal3<T> &a, const Normal3<T> &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template<typename T>
Normal3<T> cross(const Normal3<T> &a, const Normal3<T> &b)
{
    return Normal3<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

template<typename T>
T length_squared(const Normal3<T> &a)
{
    return dot(a, a);
}

template<typename T>
T length(const Normal3<T> &a)
{
    return std::sqrt(length_squared(a));
}

template<typename T>
Normal3<T> normalize(const Normal3<T> &a)
{
    return a / length(a);
}