template<typename T>
Point2<T>::Point2()
        : x(0), y(0)
{

}

template<typename T>
Point2<T>::Point2(T x, T y)
        : x(x), y(y)
{

}

template<typename T>
template<typename U>
Point2<T>::Point2(const Vector2<U> &v)
        : x(T(v.x)), y(T(v.y))
{

}

template<typename T>
template<typename U>
Point2<T>::Point2(const Point2<U> &p)
        : x(T(p.x)), y(T(p.y))
{

}

template<typename T>
Point2<T> Point2<T>::operator-() const
{
    return Point2<T>(-x, -y);
}

template<typename T>
Point2<T> Point2<T>::operator+(const Vector2<T> &v) const
{
    return Point2<T>(x + v.x, y + v.y);
}

template<typename T>
Point2<T> Point2<T>::operator-(const Vector2<T> &v) const
{
    return Point2<T>(x - v.x, y - v.y);
}

template<typename T>
Vector2<T> Point2<T>::operator-(const Point2<T> &v) const
{
    return Vector2<T>(x - v.x, y - v.y);
}

template<typename T>
Point2<T> Point2<T>::operator*(Float f) const
{
    return Point2<T>(x * f, y * f);
}

template<typename T>
Point2<T> Point2<T>::operator/(Float s) const
{
    Float f = Float(1) / s;
    return Point2<T>(x * f, y * f);
}

template<typename T>
Point2<T> &Point2<T>::operator*=(Float f)
{
    x *= f;
    y *= f;

    return *this;
}

template<typename T>
Point2<T> &Point2<T>::operator/=(Float s)
{
    Float f = Float(1) / s;
    x *= f;
    y *= f;

    return *this;
}

template<typename T>
bool Point2<T>::operator==(const Point2<T> &v) const
{
    return x == v.x && y == v.y;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Point2<T> &p)
{
    return os << "{ " << p.x << " " << p.y << " }";
}

template<typename T>
Point2<T> operator*(Float f, const Point2<T> &v)
{
    return v * f;
}

template<typename T>
Point2<T> max(const Point2<T> &a, const Point2<T> &b)
{
    return Point2<T>(max(a.x, b.x), max(a.y, b.y));
}

template<typename T>
Point2<T> min(const Point2<T> &a, const Point2<T> &b)
{
    return Point2<T>(min(a.x, b.x), min(a.y, b.y));
}

template<typename T>
Point2<T> ceil(const Point2<T> &p)
{
    return Point2<T>(std::ceil(p.x), std::ceil(p.y));
}

template<typename T>
Point2<T> floor(const Point2<T> &p)
{
    return Point2<T>(std::floor(p.x), std::floor(p.y));
}