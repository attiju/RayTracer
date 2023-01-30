#ifndef CORE_HH
#define CORE_HH

#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>

typedef double Float;

inline const constexpr Float pi        = 3.14159265358979323846;
inline const constexpr Float inv_pi    = 0.31830988618379067154;
inline const constexpr Float inv_2_pi  = 0.15915494309189533577;
inline const constexpr Float inv_4_pi  = 0.07957747154594766788;
inline const constexpr Float pi_over_2 = 1.57079632679489661923;
inline const constexpr Float pi_over_4 = 0.78539816339744830961;
inline const constexpr Float sqrt_2    = 1.41421356237309504880;
inline const constexpr Float inf       = std::numeric_limits<Float>::infinity();

template<typename T>
class Point2;

template<typename T>
class Point3;

template<typename T>
class Vector2;

template<typename T>
class Vector3;

template<typename T>
class Normal3;

class Ray;

class Matrix4x4;

class Transform;

class Shape;

class Interaction;

class SurfaceInteraction;

inline Float radians(Float degrees);

inline Float degrees(Float radians);

template<typename T>
inline T min(T a, T b);

template<typename T>
inline T max(T a, T b);

template<typename T, typename MIN, typename MAX>
inline T clamp(T x, MIN m, MAX M);

inline bool solve_quadratic(Float a, Float b, Float c, Float *x0, Float *x1);

#include <core.inl>

#endif