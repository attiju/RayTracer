#ifndef SPECTRUM_HH
#define SPECTRUM_HH

#include <core.hpp>

#include <point_3.hpp>
#include <vector_3.hpp>
#include <normal_3.hpp>

class Spectrum {
public:
    inline Spectrum();

    inline Spectrum(Float v);

    inline Spectrum(Float x, Float y, Float z);

    template<typename T>
    inline Spectrum(const Point3<T>);

    template<typename T>
    inline Spectrum(const Vector3<T>);

    template<typename T>
    inline Spectrum(const Normal3<T>);

public:
    inline Spectrum operator-() const;

    inline Spectrum operator+(const Spectrum &v) const;

    inline Spectrum operator-(const Spectrum &v) const;

    inline Spectrum operator*(const Spectrum& s) const;

    inline Spectrum operator*(Float f) const;

    inline Spectrum operator/(Float s) const;

    inline Spectrum &operator+=(const Spectrum &v);

    inline Spectrum &operator-=(const Spectrum &v);

    inline Spectrum &operator*=(Float f);

    inline Spectrum &operator/=(Float s);

    inline Float operator[](int i) const;

public:
    Float x, y, z;
};

std::ostream &operator<<(std::ostream &os, const Spectrum &spectrum);

#include <spectrum.inl>

#endif