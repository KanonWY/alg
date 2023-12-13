#include "tree.h"
#include <algorithm>
#include <gtest/gtest.h>

/**
 * \breif 返回当前树的最大深度
 *
 */

class Solution
{
public:
    static int depthOfTree(TreeNode* node)
    {
        // 如果当前树为空，而深度为0
        if (!node) return 0;
        return 1 + std::max(depthOfTree(node->left), depthOfTree(node->right));
    }
};

/**
 *
 *               a
 *              /
 *             b
 *            /
 *           c
 *          /
 *         d
 *        /
 *       e
 *       /
 *      f
 *
 *
 */

TEST(tree, depth1)
{
    auto a = new TreeNode(1);
    auto b = new TreeNode(2);
    auto c = new TreeNode(1);
    auto d = new TreeNode(1);
    auto e = new TreeNode(1);
    auto f = new TreeNode(1);

    a->left = b;
    b->left = c;
    c->left = d;
    d->left = e;
    e->left = f;
    EXPECT_EQ(Solution::depthOfTree(a), 6);
    deleteTree(a);
}

/**
 *          a
 *         /  \
 *         b   c
 *        / \
 *       d   e
 *
 */

TEST(tree, depth2)
{
    auto a = new TreeNode(1);
    auto b = new TreeNode(2);
    auto c = new TreeNode(1);
    auto d = new TreeNode(1);
    auto e = new TreeNode(1);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    EXPECT_EQ(Solution::depthOfTree(a), 3);

    deleteTree(a);
}
