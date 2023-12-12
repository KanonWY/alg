#include "tree.h"
#include <gtest/gtest.h>

TEST(tree, protravel)
{
    auto* root = buildTree();
    std::vector<int> res2;  
    const auto res1 = preorderTravel(root);
    preorderTravel(root, res2);
    
    EXPECT_EQ(res1, res2);
  
    deleteTree(root);
}
