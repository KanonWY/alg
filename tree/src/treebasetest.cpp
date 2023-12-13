#include "tree.h"
#include <gtest/gtest.h>

/**
 *          1
 *         / \
 *        2   3
 *      / \   / \
 *     4   5 6   7
 *
 *    1 2 4 5 3 6 7
 *    4 2 5 1 6 3 7
 */

TEST(tree, protravel)
{
    auto* root = buildTree();
    std::vector<int> res2;
    const auto res1 = preorderTravel(root);
    preorderTravel(root, res2);

    EXPECT_EQ(res1, res2);

    deleteTree(root);
}

TEST(tree, Pirntlayertravel)
{
    // 构建树
    auto* root = buildTree();
    PrintTreeByLayer(root);
    // 删除树
    deleteTree(root);
    EXPECT_EQ(42, 6 * 7);
}

TEST(tree, middletravel)
{
    auto* root = buildTree();

    std::vector<int> out;
    auto res1 = midorderTravel(root);
    midorderTravel(root, out);
    deleteTree(root);
    EXPECT_EQ(out, res1);
}

TEST(tree, posttravel)
{
    auto* root = buildTree();
    std::vector<int> out;
    postorderTravel(root, out);

    auto result = postorderTravel(root);
    deleteTree(root);
    EXPECT_EQ(out, result);
}

TEST(tree, depth)
{
    auto* root = buildTree();
    EXPECT_EQ(depthOfTree(root), 3);
    deleteTree(root);
}
