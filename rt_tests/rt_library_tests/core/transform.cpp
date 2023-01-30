#include "../../catch.hpp"

#include "core/transform.hpp"

TEST_CASE("test_transform_default_is_identity")
{
    auto T = Transform();

    REQUIRE(T.m == Matrix4x4());
    REQUIRE(T.m == T.m_inv);
}

TEST_CASE("test_transform_inverse")
{
    auto T = Transform();

    REQUIRE(inverse(inverse(T)) == T);
}

TEST_CASE("test_transform_translate")
{
    auto T = translate(Vector3f(1, -2, 3));
    auto p = Point3f(0, 0, 0);
    auto v = Vector3f(1, 2, 3);
    auto n = Normal3f(0, 1, 0);
    REQUIRE(T(p) == Point3f(1, -2, 3));
    REQUIRE(T(v) == v);
    REQUIRE(T(n) == n);
}


TEST_CASE("test_transform_composition")
{
    auto T1 = translate(Vector3f(0, 0, -1))
            * scale(10, 10, 10);

    auto T2 = scale(10, 10, 10)
            * translate(Vector3f(0, 0, -1));

    auto T3 = rotateX(90)
            * translate(Vector3f(0, 0, -1));

    REQUIRE(T1(Point3f(0, 0, 0)) == Point3f(0, 0, -1));
    REQUIRE(T2(Point3f(0, 0, 0)) == Point3f(0, 0, -10));
    REQUIRE(T3(Point3i(0, 0, 0)) == Point3i(0, 1, 0));
    REQUIRE(T1(Vector3f(1, 2, 3)) == Vector3f(10, 20, 30));
    REQUIRE(T2(Vector3f(0, 0, 0)) == Vector3f(0, 0, 0));
    REQUIRE(T3(Vector3i(0, 0, -1)) == Vector3i(0, 1, 0));
    REQUIRE(T3(Normal3i(1, 1, 0)) == Normal3i(1, 0, 1));
}