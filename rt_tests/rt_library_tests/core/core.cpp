#include "../../catch.hpp"

#include "core.hpp"

TEST_CASE("radians(90) == (pi / 2)")
{
    REQUIRE(radians(90) == pi_over_2);
}

TEST_CASE("radians(45) == (pi / 4)")
{
    REQUIRE(radians(45) == pi_over_4);
}

TEST_CASE("degrees(pi / 3) == 60")
{
    REQUIRE(degrees(pi / 3) == 60);
}

TEST_CASE("min(..., ...)")
{
    Float A[5] = {-4., -1., 1., 1.1, 1.2};
    Float B[5] = {-1.8, 2.2, 1.1, 1.1, 11.};

    for (int i = 0; i < 5; i++) {
        REQUIRE(min(A[i], B[i]) == A[i]);
    }
}

TEST_CASE("max(..., ...)")
{
    Float A[5] = {-4., -1., 1., 1.1, 1.2};
    Float B[5] = {-1.8, 2.2, 1.1, 1.1, 11.};

    for (int i = 0; i < 5; i++) {
        REQUIRE(max(A[i], B[i]) == B[i]);
    }
}

TEST_CASE("clamp(..., ..., ...)")
{
    Float X[5] = {-4., -1., 1.7, 1.1, 110.2};
    Float m[5] = {-1.8, 2.2, 1.1, 1.1, 11.};
    Float M[5] = {10.8, 3.2, 5.1, 7.1, 12.};
    Float R[5] = {-1.8, 2.2, 1.7, 1.1, 12.};

    for (int i = 0; i < 5; i++) {
        REQUIRE(clamp(X[i], m[i], M[i]) == R[i]);
    }
}