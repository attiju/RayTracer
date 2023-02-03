#ifndef MATRIX_4_4_HH
#define MATRIX_4_4_HH

#include <core.hpp>

class Matrix4x4 {
 public:
  inline Matrix4x4();

  inline Matrix4x4(
      Float m00,
      Float m01,
      Float m02,
      Float m03,
      Float m10,
      Float m11,
      Float m12,
      Float m13,
      Float m20,
      Float m21,
      Float m22,
      Float m23,
      Float m30,
      Float m31,
      Float m32,
      Float m33
  );

 public:
  inline Matrix4x4 operator*(const Matrix4x4 &M) const;

 public:
  inline bool operator==(const Matrix4x4 &M) const;

 public:
  Float m[4][4];
};

std::ostream &operator<<(std::ostream &os, const Matrix4x4 &M);

inline Matrix4x4 inverse(const Matrix4x4 &M);

inline Matrix4x4 transpose(const Matrix4x4 &M);

#include <matrix_4_4.inl>

#endif