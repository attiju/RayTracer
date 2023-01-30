#include <matrix_4_4.hpp>

std::ostream &operator<<(std::ostream &os, const Matrix4x4 &M)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            os << M.m[i][j] << " ";
        }
        os << std::endl;
    }

    return os;
}