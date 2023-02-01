#include "../../catch.hpp"

#include "transform.hpp"

template<class P, class V>
inline bool almost_equal(const P &a, const V &b)
{
    auto eps  = 1e-4;
    auto diff = abs(b - a);

    return diff.x <= eps && diff.y <= eps && diff.z <= eps;
}

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

TEST_CASE("test_transform_look_at")
{
    auto eye    = Point3f(0, 5, 0);
    auto target = Point3f(5, 5, -5);

    auto T = lookAt(eye, target);

    REQUIRE(T(Vector3f(0, 0, -1)) == normalize(Vector3f(1, 0, -1)));
    REQUIRE(T(Point3f(0, 0, 0)) == eye);
    REQUIRE(almost_equal(T(Point3f(-1, 0, 0)), eye + normalize(Vector3f(-1, 0, -1))));
    REQUIRE(almost_equal(T(Point3f(1, 0, 0)), eye + normalize(Vector3f(1, 0, 1))));
}