Float radians(Float degrees)
{
    return pi * degrees / 180;
}

Float degrees(Float radians)
{
    return 180 * radians * inv_pi;
}

template<typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}

template<typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template<typename T, typename MIN, typename MAX>
T clamp(T x, MIN m, MAX M)
{
    return x < m ? m : x > M ? M : x;
}
