template<typename T>
Bounds2<T>::Bounds2() {
    T lowest_value = std::numeric_limits<T>::lowest();
    T max_value    = std::numeric_limits<T>::max();
    p_min = Point2<T>(max_value, max_value);
    p_max = Point2<T>(lowest_value, lowest_value);
}

template<typename T>
Bounds2<T>::Bounds2(const Point2<T> &a, const Point2<T> &b)
        : p_min(Point2<T>(std::min(a.x, b.x), std::min(a.y, b.y))),
          p_max(Point2<T>(std::max(a.x, b.x), std::max(a.y, b.y))) {
}

template<typename T>
Bounds2<T>::Bounds2(const Point2<T> &p)
        :p_min(p), p_max(p) {

}

template<typename T>
Vector2<T> Bounds2<T>::diagonal() const { return p_max - p_min; }

template<typename T>
T Bounds2<T>::area() const {
    auto diag = diagonal();
    return diag.x * diag.y;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Bounds2<T> &bounds2) {
    return os << "{ p_min: " << bounds2.p_min << " p_max: " << bounds2.p_max << " }";
}
