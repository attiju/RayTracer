Float radians(Float degrees) {
    return pi * degrees / 180;
}

Float degrees(Float radians) {
    return 180 * radians * inv_pi;
}

template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template<typename T, typename MIN, typename MAX>
T clamp(T x, MIN m, MAX M) {
    return x < m ? m : x > M ? M : x;
}

bool solve_quadratic(Float a, Float b, Float c, Float *x0, Float *x1) {
    Float d = b * b - 4 * a * c;

    if (d < 0) return false;
    d = std::sqrt(d);

    double q;
    if (b < 0) {
        q = -.5 * (b - d);
    } else {
        q = -.5 * (b + d);
    }

    *x0 = q / a;
    *x1 = c / q;
    if (*x0 > *x1) std::swap(*x0, *x1);
    return true;
}
