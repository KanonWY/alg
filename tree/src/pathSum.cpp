#include "tree.h"
#include <gtest/gtest.h>

/**
 *\brief 给定一个整数二叉树，求有多少条路径节点值之和为给定值
 *
 *
 */
class Solution
{
public:
    static int pathSum(TreeNode* node, int sum)
    {
        return node ? pathSumStartWithRoot(node, sum) +
                          pathSum(node->left, sum) + pathSum(node->right, sum)
                    : 0;

        return 0;
    }

private:
    static int pathSumStartWithRoot(TreeNode* root, int sum)
    {
        if (!root) return 0;
        int count = root->value == sum ? 1 : 0;
        count += pathSumStartWithRoot(root->left, sum - root->value);
        count += pathSumStartWithRoot(root->right, sum - root->value);
        return count;
    }
};

/**
 *
 *
 *               1
 *             /    \
 *            2       3
 *          /   \    /  \
 *         3     4  2    2
 *        /
 *       3
 *
 *    sum: 6
 *    [1,2,3] [1,3,2] [1,3,2]  [3,3] [2,1,3]
 *    res: 5
 */

TEST(tree, pathSum1)
{
    auto a = new TreeNode(1);
    auto b = new TreeNode(2);
    auto c = new TreeNode(3);
    auto d = new TreeNode(3);
    auto e = new TreeNode(4);
    auto f = new TreeNode(2);
    auto g = new TreeNode(2);
    auto h = new TreeNode(3);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->left = h;

    deleteTree(a);
}

/**
 *                10
 *               /   \
 *              5     -3
 *            /  \      \
 *           3    2     11
 *         /  \    \
 *        3   -2    1
 *
 *     sum:8
 *     [5,3], [5,2,1], [-3,11]
 *
 *     res: 3
 */

TEST(tree, pathSum2)
{
    auto a = new TreeNode(10);
    auto b = new TreeNode(5);
    auto c = new TreeNode(-3);
    auto d = new TreeNode(3);
    auto e = new TreeNode(2);
    auto f = new TreeNode(11);
    auto g = new TreeNode(3);
    auto h = new TreeNode(-2);
    auto i = new TreeNode(1);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    d->left = g;
    d->right = h;
    e->right = i;

    deleteTree(a);
}
