#include "tree.h"
#include <algorithm>
#include <gtest/gtest.h>

/**
 *
 *\brief 判断一颗是是否平衡
 *       平衡树的概念：树上任意节点，两侧节点的最大深度差值不得大于1
 */

class Solution
{
public:
    static bool isBalanced(TreeNode* node) { return helper(node) != -1; }

private:
    // 返回以当前节点为父节点的最大深度
    // 如果返回 -1 表明当前节点为父节点的树已经不是一棵平衡树
    static int helper(TreeNode* node)
    {
        // 如果是空节点，当前深度为 0
        if (!node) return 0;
        // 递归求取左、右子树的最大深度
        int left = helper(node->left), right = helper(node->right);
        // 如果左子树和右子树已经不是平衡树了就返回-1，如果左右子树的深度差大于1，返回-1
        // 表明以该节点为父亲的节点的子树已经不平衡
        if (left == -1 || right == -1 || std::abs(left - right) > 1)
        {
            return -1;
        }
        // 返回当前节点为父亲节点的最大深度
        return std::max(left, right) + 1;
    }
};

TEST(tree, isbalance1)
{
    auto* node = buildTree();
    EXPECT_EQ(Solution::isBalanced(node), true);
    deleteTree(node);
}

/**
 *        a
 *       /  \
 *      b    c
 *    /  \
 *   d    e
 *  / \
 * f   g
 */

TEST(tree, isbalance2)
{
    auto a = new TreeNode(1);
    auto b = new TreeNode(1);
    auto c = new TreeNode(1);
    auto d = new TreeNode(1);
    auto e = new TreeNode(1);
    auto f = new TreeNode(1);
    auto g = new TreeNode(1);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = f;
    d->right = g;

    EXPECT_EQ(Solution::isBalanced(a), false);

    deleteTree(a);
}

/**
 *     a
 *    /
 *   b
 *  /
 *  c
 * /
 * d
 */

TEST(tree, isbalance3)
{
    auto a = new TreeNode(1);
    auto b = new TreeNode(1);
    auto c = new TreeNode(1);
    auto d = new TreeNode(1);

    a->left = b;
    b->left = c;
    c->left = d;

    EXPECT_EQ(Solution::isBalanced(a), false);
    deleteTree(a);
}
