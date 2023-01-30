#include "../../catch.hpp"

#include "core/matrix_4_4.hpp"

TEST_CASE("test_matrix_default_is_identity")
{
    auto identity = Matrix4x4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
    );

    REQUIRE(Matrix4x4() == identity);
};

TEST_CASE("test_matrix_transpose")
{
    auto M = Matrix4x4(
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
    );

    auto M_tr = Matrix4x4(
            1, 5, 9, 13,
            2, 6, 10, 14,
            3, 7, 11, 15,
            4, 8, 12, 16
    );

    REQUIRE(transpose(M) == M_tr);
};

TEST_CASE("test_matrix_mul")
{
    auto A = Matrix4x4(
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
    );

    auto B = Matrix4x4(
            1, 5, 9, 13,
            2, 6, 10, 14,
            3, 7, 11, 15,
            4, 8, 12, 16
    );

    auto R = Matrix4x4(
            30, 70, 110, 150,
            70, 174, 278, 382,
            110, 278, 446, 614,
            150, 382, 614, 846
    );

    REQUIRE((A * B) == R);
};

TEST_CASE("test_matrix_inverse")
{
    auto M = Matrix4x4(
            1, 2, 1, 2,
            0, 0, 0, 1,
            1, 1, 0, 2,
            0, 1, 2, 1
    );

    auto M_inv = Matrix4x4(
            -2, -3, 3, 1,
            2, 1, -2, -1,
            -1, -1, 1, 1,
            0, 1, 0, -0
    );

    REQUIRE(inverse(M) == M_inv);
};

TEST_CASE("test_matrix_inverse_inverse")
{
    auto M = Matrix4x4(
            1, 2, 1, 2,
            0, 0, 0, 1,
            1, 1, 0, 2,
            0, 1, 2, 1
    );

    REQUIRE(inverse(inverse(M)) == M);
};