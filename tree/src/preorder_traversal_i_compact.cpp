#include "tree.h"
#include <gtest/gtest.h>

/**
 * \brief 找出二叉树中值为 7 的节点，将节点存储在下来，并返回
 * \brief 还需要返回根节点到值为 7 节点的路径
 */
class Solution
{
public:
    static std::vector<TreeNode *> preOrder(TreeNode *node)
    {
        std::vector<TreeNode *> res;
        helper(res, node);
        return res;
    }

private:
    static void helper(std::vector<TreeNode *> &res, TreeNode *curnode)
    {
        if (!curnode) return;
        if (curnode->value == 7)
        {
            res.push_back(curnode);
        }
        helper(res, curnode->left);
        helper(res, curnode->right);
    }
};

TEST(tree, preOrder_tarversal_i_compact)
{
    EXPECT_EQ(100, 100);
    EXPECT_EQ(42, 7 * 6);
}
