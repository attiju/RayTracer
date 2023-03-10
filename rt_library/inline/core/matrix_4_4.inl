
Matrix4x4::Matrix4x4() {
  m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1;
  m[0][1] = m[0][2] = m[0][3] = 0;
  m[1][0] = m[1][2] = m[1][3] = 0;
  m[2][0] = m[2][1] = m[2][3] = 0;
  m[3][0] = m[3][1] = m[3][2] = 0;
}

Matrix4x4::Matrix4x4(Float m00,
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
                     Float m33) {
  m[0][0] = m00;
  m[0][1] = m01;
  m[0][2] = m02;
  m[0][3] = m03;
  m[1][0] = m10;
  m[1][1] = m11;
  m[1][2] = m12;
  m[1][3] = m13;
  m[2][0] = m20;
  m[2][1] = m21;
  m[2][2] = m22;
  m[2][3] = m23;
  m[3][0] = m30;
  m[3][1] = m31;
  m[3][2] = m32;
  m[3][3] = m33;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &M) const {
  return Matrix4x4(
      m[0][0] * M.m[0][0] + m[0][1] * M.m[1][0] + m[0][2] * M.m[2][0] + m[0][3] * M.m[3][0],
      m[0][0] * M.m[0][1] + m[0][1] * M.m[1][1] + m[0][2] * M.m[2][1] + m[0][3] * M.m[3][1],
      m[0][0] * M.m[0][2] + m[0][1] * M.m[1][2] + m[0][2] * M.m[2][2] + m[0][3] * M.m[3][2],
      m[0][0] * M.m[0][3] + m[0][1] * M.m[1][3] + m[0][2] * M.m[2][3] + m[0][3] * M.m[3][3],
      m[1][0] * M.m[0][0] + m[1][1] * M.m[1][0] + m[1][2] * M.m[2][0] + m[1][3] * M.m[3][0],
      m[1][0] * M.m[0][1] + m[1][1] * M.m[1][1] + m[1][2] * M.m[2][1] + m[1][3] * M.m[3][1],
      m[1][0] * M.m[0][2] + m[1][1] * M.m[1][2] + m[1][2] * M.m[2][2] + m[1][3] * M.m[3][2],
      m[1][0] * M.m[0][3] + m[1][1] * M.m[1][3] + m[1][2] * M.m[2][3] + m[1][3] * M.m[3][3],
      m[2][0] * M.m[0][0] + m[2][1] * M.m[1][0] + m[2][2] * M.m[2][0] + m[2][3] * M.m[3][0],
      m[2][0] * M.m[0][1] + m[2][1] * M.m[1][1] + m[2][2] * M.m[2][1] + m[2][3] * M.m[3][1],
      m[2][0] * M.m[0][2] + m[2][1] * M.m[1][2] + m[2][2] * M.m[2][2] + m[2][3] * M.m[3][2],
      m[2][0] * M.m[0][3] + m[2][1] * M.m[1][3] + m[2][2] * M.m[2][3] + m[2][3] * M.m[3][3],
      m[3][0] * M.m[0][0] + m[3][1] * M.m[1][0] + m[3][2] * M.m[2][0] + m[3][3] * M.m[3][0],
      m[3][0] * M.m[0][1] + m[3][1] * M.m[1][1] + m[3][2] * M.m[2][1] + m[3][3] * M.m[3][1],
      m[3][0] * M.m[0][2] + m[3][1] * M.m[1][2] + m[3][2] * M.m[2][2] + m[3][3] * M.m[3][2],
      m[3][0] * M.m[0][3] + m[3][1] * M.m[1][3] + m[3][2] * M.m[2][3] + m[3][3] * M.m[3][3]
  );
}

bool Matrix4x4::operator==(const Matrix4x4 &M) const {
  for (int i = 0;
       i < 4;
       ++i) {
    for (int j = 0;
         j < 4;
         ++j) {
      if (m[i][j] != M.m[i][j]) { return false; }
    }
  }
  return true;
}

Matrix4x4 inverse(const Matrix4x4 &M) {
  Float A2323 = M.m[2][2] * M.m[3][3] - M.m[2][3] * M.m[3][2];
  Float A1323 = M.m[2][1] * M.m[3][3] - M.m[2][3] * M.m[3][1];
  Float A1223 = M.m[2][1] * M.m[3][2] - M.m[2][2] * M.m[3][1];
  Float A0323 = M.m[2][0] * M.m[3][3] - M.m[2][3] * M.m[3][0];
  Float A0223 = M.m[2][0] * M.m[3][2] - M.m[2][2] * M.m[3][0];
  Float A0123 = M.m[2][0] * M.m[3][1] - M.m[2][1] * M.m[3][0];
  Float A2313 = M.m[1][2] * M.m[3][3] - M.m[1][3] * M.m[3][2];
  Float A1313 = M.m[1][1] * M.m[3][3] - M.m[1][3] * M.m[3][1];
  Float A1213 = M.m[1][1] * M.m[3][2] - M.m[1][2] * M.m[3][1];
  Float A2312 = M.m[1][2] * M.m[2][3] - M.m[1][3] * M.m[2][2];
  Float A1312 = M.m[1][1] * M.m[2][3] - M.m[1][3] * M.m[2][1];
  Float A1212 = M.m[1][1] * M.m[2][2] - M.m[1][2] * M.m[2][1];
  Float A0313 = M.m[1][0] * M.m[3][3] - M.m[1][3] * M.m[3][0];
  Float A0213 = M.m[1][0] * M.m[3][2] - M.m[1][2] * M.m[3][0];
  Float A0312 = M.m[1][0] * M.m[2][3] - M.m[1][3] * M.m[2][0];
  Float A0212 = M.m[1][0] * M.m[2][2] - M.m[1][2] * M.m[2][0];
  Float A0113 = M.m[1][0] * M.m[3][1] - M.m[1][1] * M.m[3][0];
  Float A0112 = M.m[1][0] * M.m[2][1] - M.m[1][1] * M.m[2][0];

  Float det = M.m[0][0] * (M.m[1][1] * A2323 - M.m[1][2] * A1323 + M.m[1][3] * A1223)
      - M.m[0][1] * (M.m[1][0] * A2323 - M.m[1][2] * A0323 + M.m[1][3] * A0223)
      + M.m[0][2] * (M.m[1][0] * A1323 - M.m[1][1] * A0323 + M.m[1][3] * A0123)
      - M.m[0][3] * (M.m[1][0] * A1223 - M.m[1][1] * A0223 + M.m[1][2] * A0123);

  det = Float(1) / det;

  return Matrix4x4(
      det * (M.m[1][1] * A2323 - M.m[1][2] * A1323 + M.m[1][3] * A1223),
      det * -(M.m[0][1] * A2323 - M.m[0][2] * A1323 + M.m[0][3] * A1223),
      det * (M.m[0][1] * A2313 - M.m[0][2] * A1313 + M.m[0][3] * A1213),
      det * -(M.m[0][1] * A2312 - M.m[0][2] * A1312 + M.m[0][3] * A1212),
      det * -(M.m[1][0] * A2323 - M.m[1][2] * A0323 + M.m[1][3] * A0223),
      det * (M.m[0][0] * A2323 - M.m[0][2] * A0323 + M.m[0][3] * A0223),
      det * -(M.m[0][0] * A2313 - M.m[0][2] * A0313 + M.m[0][3] * A0213),
      det * (M.m[0][0] * A2312 - M.m[0][2] * A0312 + M.m[0][3] * A0212),
      det * (M.m[1][0] * A1323 - M.m[1][1] * A0323 + M.m[1][3] * A0123),
      det * -(M.m[0][0] * A1323 - M.m[0][1] * A0323 + M.m[0][3] * A0123),
      det * (M.m[0][0] * A1313 - M.m[0][1] * A0313 + M.m[0][3] * A0113),
      det * -(M.m[0][0] * A1312 - M.m[0][1] * A0312 + M.m[0][3] * A0112),
      det * -(M.m[1][0] * A1223 - M.m[1][1] * A0223 + M.m[1][2] * A0123),
      det * (M.m[0][0] * A1223 - M.m[0][1] * A0223 + M.m[0][2] * A0123),
      det * -(M.m[0][0] * A1213 - M.m[0][1] * A0213 + M.m[0][2] * A0113),
      det * (M.m[0][0] * A1212 - M.m[0][1] * A0212 + M.m[0][2] * A0112)
  );
}

inline Matrix4x4 transpose(const Matrix4x4 &M) {
  return Matrix4x4(
      M.m[0][0], M.m[1][0], M.m[2][0], M.m[3][0],
      M.m[0][1], M.m[1][1], M.m[2][1], M.m[3][1],
      M.m[0][2], M.m[1][2], M.m[2][2], M.m[3][2],
      M.m[0][3], M.m[1][3], M.m[2][3], M.m[3][3]
  );
}