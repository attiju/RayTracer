template<typename T>
Vector3<T>::Vector3()
        : x(0), y(0), z(0) {

}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z)
        : x(x), y(y), z(z) {

}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Vector3<U> &v)
        : x(T(v.x)), y(T(v.y)), z(T(v.z)) {

}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Point3<U> &p)
        : x(T(p.x)), y(T(p.y)), z(T(p.z)) {

}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Normal3<U> &n)
        : x(T(n.x)), y(T(n.y)), z(T(n.z)) {

}

template<typename T>
Vector3<T> Vector3<T>::operator-() const {
    return Vector3<T>(-x, -y, -z);
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &v) const {
    return Vector3<T>(x + v.x, y + v.y, z + v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &v) const {
    return Vector3<T>(x - v.x, y - v.y, z - v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(Float f) const {
    return Vector3<T>(x * f, y * f, z * f);
}

template<typename T>
Vector3<T> Vector3<T>::operator/(Float s) const {
    Float f = Float(1) / s;
    return Vector3<T>(x * f, y * f, z * f);
}

template<typename T>
Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &v) {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

template<typename T>
Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

template<typename T>
Vector3<T> &Vector3<T>::operator*=(Float f) {
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
Vector3<T> &Vector3<T>::operator/=(Float s) {
    Float f = Float(1) / s;
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<typename T>
T Vector3<T>::operator[](int i) const {
    return i == 0 ? x : i  == 1 ? y : z;
}

template<typename T>
bool Vector3<T>::operator==(const Vector3<T> &v) const {
    return x == v.x && y == v.y && z == v.z;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3<T> &v) {
    return os << "{ " << v.x << " " << v.y << " " << v.z << " }";
}

template<typename T>
Vector3<T> operator*(Float f, const Vector3<T> &v) {
    return v * f;
}

template<typename T>
inline Vector3<T> abs(const Vector3<T> &a) {
    return Vector3<T>(std::abs(a.x), std::abs(a.y), std::abs(a.z));
}

template<typename T>
T dot(const Vector3<T> &a, const Vector3<T> &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template<typename T>
Vector3<T> cross(const Vector3<T> &a, const Vector3<T> &b) {
    return Vector3<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

template<typename T>
T length_squared(const Vector3<T> &a) {
    return dot(a, a);
}

template<typename T>
T length(const Vector3<T> &a) {
    return std::sqrt(length_squared(a));
}

template<typename T>
Vector3<T> normalize(const Vector3<T> &a) {
    return a / length(a);
}
