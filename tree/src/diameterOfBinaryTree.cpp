#include "tree.h"
#include <gtest/gtest.h>

/**
 *\breif
 *输出一个二叉树的最长直径，直径的定义为二叉树上任意两个节点之间的无向距离
 *
 *            curNode
 *           /      \
 *         left    right
 */

class Solution
{
public:
    static int diameterOfBinaryTree(TreeNode* node)
    {
        int diameter = 0;
        helper(node, diameter);
        return diameter;
    }

private:
    // diameter 表示经过 node 节点的最长的直径
    // 返回值表示以该子树根节点为端点的最大长直径
    static int helper(TreeNode* node, int& diameter)
    {
        // 如果当前节点为空，那么以当前节点为端口的直径长度为空
        if (!node) return 0;
        
        // left node longest
        int left = helper(node->left, diameter),
            right = helper(node->right, diameter);

        // 更新全局最长直径
        diameter = std::max(left + right, diameter);

        // 返回以该节点为端点的最长路径
        return std::max(left, right) + 1;
    }
};

/**
 *
 *               a
 *              /  \
 *             b    c
 *            / \   / \
 *           d   e  f  g
 *          /
 *         h
 *
 */

TEST(tree, diameterOfBinaryTree1)
{
    auto a = new TreeNode(1);
    auto b = new TreeNode(1);
    auto c = new TreeNode(1);
    auto d = new TreeNode(1);
    auto e = new TreeNode(1);
    auto f = new TreeNode(1);
    auto g = new TreeNode(1);
    auto h = new TreeNode(1);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = h;
    c->left = f;
    c->right = g;

    EXPECT_EQ(Solution::diameterOfBinaryTree(a), 5);

    deleteTree(a);
}

/**
 *
 *           a
 *          / \
 *         b   c
 *        / \   \
 *       d   e   g
 *      /         \
 *     f           h
 *
 */

TEST(tree, diameterOfBinaryTree2)
{
    auto a = new TreeNode(1);
    auto b = new TreeNode(1);
    auto c = new TreeNode(1);
    auto d = new TreeNode(1);
    auto e = new TreeNode(1);
    auto f = new TreeNode(1);
    auto g = new TreeNode(1);
    auto h = new TreeNode(1);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = f;
    c->right = g;
    g->right = h;

    EXPECT_EQ(Solution::diameterOfBinaryTree(a), 6);

    deleteTree(a);
}
