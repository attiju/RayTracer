template<typename T>
Vector3<T>::Vector3()
        : x(0), y(0), z(0)
{

}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z)
        : x(x), y(y), z(z)
{

}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Vector3<U> &v)
        : x(T(v.x)), y(T(v.y)), z(T(v.z))
{

}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Point3<U> &p)
        : x(T(p.x)), y(T(p.y)), z(T(p.z))
{

}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Normal3<U> &n)
        : x(T(n.x)), y(T(n.y)), z(T(n.z))
{

}


template<typename T>
Vector3<T> Vector3<T>::operator-() const
{
    return Vector3<T>(-x, -y, -z);
}


template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &v) const
{
    return Vector3<T>(x + v.x, y + v.y, z + v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &v) const
{
    return Vector3<T>(x - v.x, y - v.y, z - v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(Float f) const
{
    return Vector3<T>(x * f, y * f, z * f);
}

template<typename T>
Vector3<T> Vector3<T>::operator/(Float s) const
{
    Float f = Float(1) / s;
    return Vector3<T>(x * f, y * f, z * f);
}

template<typename T>
Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

template<typename T>
Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

template<typename T>
Vector3<T> &Vector3<T>::operator*=(Float f)
{
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
Vector3<T> &Vector3<T>::operator/=(Float s)
{
    Float f = Float(1) / s;
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
bool Vector3<T>::operator==(const Vector3<T> &v) const
{
    return x == v.x && y == v.y && z == v.z;
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3<T> &v)
{
    return os << "{ " << v.x << " " << v.y << " " << v.z << " }";
}

template<typename T>
Vector3<T> operator*(Float f, const Vector3<T> &v)
{
    return v * f;
}