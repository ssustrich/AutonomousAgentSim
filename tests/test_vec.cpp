#include <gtest/gtest.h>
#include <aas/math/Vec.h>
#include <cmath>

static constexpr float EPS = 1e-5f;

TEST(Sanity, OnePlusOne) { EXPECT_EQ(2, 1 + 1); }

TEST(VecBasics, ConstructAndIndex)
{
    Vec<2> v(1.0f, 2.0f);
    EXPECT_FLOAT_EQ(v[0], 1.0f);
    EXPECT_FLOAT_EQ(v[1], 2.0f);
}
TEST(VecBasics, DefaultZeroInit)
{
    Vec<3> v;
    EXPECT_NEAR(v[0], 0.0f, EPS);
    EXPECT_NEAR(v[1], 0.0f, EPS);
    EXPECT_NEAR(v[2], 0.0f, EPS);
}
TEST(VecBasics, PlusAndPlusEquals)
{
    Vec<3> a(1, 2, 3);
    Vec<3> b(4, 5, 6);
    Vec<3> c = a + b;
    EXPECT_NEAR(a[0], 5.0f, EPS);
    EXPECT_NEAR(a[1], 7.0f, EPS);
    EXPECT_NEAR(a[2], 9.0f, EPS);

    a += b;
    EXPECT_NEAR(c[0], 5.0f, EPS);
    EXPECT_NEAR(c[1], 7.0f, EPS);
    EXPECT_NEAR(c[2], 9.0f, EPS);
}