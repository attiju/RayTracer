template<typename T>
Normal3<T>::Normal3()
        : x(0), y(0), z(0) {

}

template<typename T>
Normal3<T>::Normal3(T x, T y, T z)
        : x(x), y(y), z(z) {

}

template<typename T>
template<typename U>
Normal3<T>::Normal3(const Normal3<U> &n)
        : x(T(n.x)), y(T(n.y)), z(T(n.z)) {

}

template<typename T>
template<typename U>
Normal3<T>::Normal3(const Vector3<U> &v)
        : x(T(v.x)), y(T(v.y)), z(T(v.z)) {

}

template<typename T>
template<typename U>
Normal3<T>::Normal3(const Point3<U> &p)
        : x(T(p.x)), y(T(p.y)), z(T(p.z)) {

}

template<typename T>
Normal3<T> Normal3<T>::operator-() const {
    return Normal3<T>(-x, -y, -z);
}

template<typename T>
Normal3<T> Normal3<T>::operator+(const Normal3<T> &v) const {
    return Normal3<T>(x + v.x, y + v.y, z + v.z);
}

template<typename T>
Normal3<T> Normal3<T>::operator-(const Normal3<T> &v) const {
    return Normal3<T>(x - v.x, y - v.y, z - v.z);
}

template<typename T>
Normal3<T> Normal3<T>::operator*(Float f) const {
    return Normal3<T>(x * f, y * f, z * f);
}

template<typename T>
Normal3<T> Normal3<T>::operator/(Float s) const {
    Float f = Float(1) / s;
    return Normal3<T>(x * f, y * f, z * f);
}

template<typename T>
Normal3<T> &Normal3<T>::operator+=(const Normal3<T> &v) {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

template<typename T>
Normal3<T> &Normal3<T>::operator-=(const Normal3<T> &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

template<typename T>
Normal3<T> &Normal3<T>::operator*=(Float f) {
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
Normal3<T> &Normal3<T>::operator/=(Float s) {
    Float f = Float(1) / s;
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
bool Normal3<T>::operator==(const Normal3<T> &v) const {
    return x == v.x && y == v.y && z == v.z;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Normal3<T> &n) {
    return os << "{ " << n.x << " " << n.y << " " << n.z << " }";
}

template<typename T>
Normal3<T> operator*(Float f, const Normal3<T> &v) {
    return v * f;
}