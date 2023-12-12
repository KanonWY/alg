#include "tree.h"
#include <gtest/gtest.h>

TEST(Hello, BasicAssert) {
    EXPECT_STRNE("hello", "woprk");
    EXPECT_EQ(7*6, 42);
}

TEST(Tree, BasicConstruct) {
    EXPECT_NE(buildTree(), nullptr);
}


TEST(Tree, vectorbase) {
    const std::vector<int> a{1, 2, 3};
    const std::vector<int> b{1, 2, 3};
    EXPECT_EQ(a, b);

    const std::vector<int> c{1, 2, 3};
    const std::vector<int> d{2, 1, 3};
    EXPECT_NE(c, d);
}
