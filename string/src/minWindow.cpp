#include <gtest/gtest.h>
#include <vector>

TEST(stringalg, baseTest)
{
    EXPECT_STRNE("12", "34");
    EXPECT_EQ(32, 4 * 8);
}

TEST(vector, baseTest)
{
    const std::vector<int> a{1, 2, 3};
    const std::vector<int> b{1, 2, 3};
    EXPECT_EQ(a, b);
}

TEST(vector, NE)
{
    const std::vector<int> c{1, 2, 3};
    const std::vector<int> d{2, 1, 3};
    EXPECT_NE(c, d);
}

TEST(vector, resize)
{
    std::vector<int> a(100);
    EXPECT_EQ(a.size(), 100);
}

TEST(vector, cap)
{
    std::vector<int> a(100);
    a.reserve(2000);
    EXPECT_GT(a.capacity(), 1000);
}
