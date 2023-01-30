template<typename T>
Vector2<T>::Vector2()
        : x(0), y(0)
{

}

template<typename T>
Vector2<T>::Vector2(T x, T y)
        : x(x), y(y)
{

}

template<typename T>
template<typename U>
Vector2<T>::Vector2(const Vector2<U> &v)
        : x(T(v.x)), y(T(v.y))
{

}

template<typename T>
template<typename U>
Vector2<T>::Vector2(const Point2<U> &p)
        : x(T(p.x)), y(T(p.y))
{

}

template<typename T>
Vector2<T> Vector2<T>::operator-() const
{
    return Vector2<T>(-x, -y);
}


template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> &v) const
{
    return Vector2<T>(x + v.x, y + v.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &v) const
{
    return Vector2<T>(x - v.x, y - v.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator*(Float f) const
{
    return Vector2<T>(x * f, y * f);
}

template<typename T>
Vector2<T> Vector2<T>::operator/(Float s) const
{
    Float f = Float(1) / s;
    return Vector2<T>(x * f, y * f);
}

template<typename T>
Vector2<T> &Vector2<T>::operator+=(const Vector2<T> &v)
{
    x += v.x;
    y += v.y;

    return *this;
}

template<typename T>
Vector2<T> &Vector2<T>::operator-=(const Vector2<T> &v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

template<typename T>
Vector2<T> &Vector2<T>::operator*=(Float f)
{
    x *= f;
    y *= f;

    return *this;
}

template<typename T>
Vector2<T> &Vector2<T>::operator/=(Float s)
{
    Float f = Float(1) / s;
    x *= f;
    y *= f;

    return *this;
}

template<typename T>
bool Vector2<T>::operator==(const Vector2<T> &v) const
{
    return x == v.x && y == v.y;
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector2<T> &v)
{
    return os << "{ " << v.x << " " << v.y << " }";
}

template<typename T>
Vector2<T> operator*(Float f, const Vector2<T> &v)
{
    return v * f;
}
