
#include "spectrum.hpp"

Spectrum::Spectrum()
    : x(0), y(0), z(0) {

}

Spectrum::Spectrum(Float v)
    : x(v), y(v), z(v) {

}

Spectrum::Spectrum(Float x, Float y, Float z)
    : x(x), y(y), z(z) {

}

template<typename T>
Spectrum::Spectrum(const Point3<T> v)
    : x(v.x), y(v.y), z(v.z) {

}

template<typename T>
Spectrum::Spectrum(const Vector3<T> v)
    : x(v.x), y(v.y), z(v.z) {

}

template<typename T>
Spectrum::Spectrum(const Normal3<T> v)
    : x(v.x), y(v.y), z(v.z) {

}

Spectrum Spectrum::operator-() const {
  return Spectrum(-x, -y, -z);
}

Spectrum Spectrum::operator+(const Spectrum &v) const {
  return Spectrum(x + v.x, y + v.y, z + v.z);
}

Spectrum Spectrum::operator-(const Spectrum &v) const {
  return Spectrum(x - v.x, y - v.y, z - v.z);
}

Spectrum Spectrum::operator*(const Spectrum &s) const {
  return Spectrum(x * s.x, y * s.y, z * s.z);
}

Spectrum Spectrum::operator*(Float f) const {
  return Spectrum(x * f, y * f, z * f);
}

Spectrum Spectrum::operator/(Float s) const {
  Float f = Float(1) / s;
  return Spectrum(x * f, y * f, z * f);
}

Spectrum &Spectrum::operator+=(const Spectrum &v) {
  x += v.x;
  y += v.y;
  z += v.z;

  return *this;
}

Spectrum &Spectrum::operator-=(const Spectrum &v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;

  return *this;
}

Spectrum &Spectrum::operator*=(Float f) {
  x *= f;
  y *= f;
  z *= f;

  return *this;
}

Spectrum &Spectrum::operator/=(Float s) {
  Float f = Float(1) / s;
  x *= f;
  y *= f;
  z *= f;

  return *this;
}

Float Spectrum::operator[](int i) const {
  return i == 0 ? x : i == 1 ? y : z;
}