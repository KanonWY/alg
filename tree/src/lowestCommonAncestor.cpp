#include "tree.h"
#include <gtest/gtest.h>

/**
 * \brief 最近公共祖先
 * \param root
 * \param p
 * \param q
 * \return
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root)
    {
        return nullptr;
    }
    return root;
}

TEST(tree, lowestCommonAncestor)
{
    // 先构建出二叉树
    auto* root = buildTree();

    EXPECT_EQ(100, 100);
    EXPECT_EQ(lowestCommonAncestor(root, root, root), root);

    // 删除掉二叉树
    deleteTree(root);
}
