#include <vector>

#include <tree.h>

class Solution
{
public:
    // 给定一个数字，求其构成的真二叉树的组合
    std::vector<TreeNode *> perfterTree(int n)
    {
        std::vector<std::vector<TreeNode *>> dp;
        dp[1] = {new TreeNode(0)};
        dp[3] = {new TreeNode(0, new TreeNode(0), new TreeNode(0))};
        for (auto item : dp[3])
        {
        }

        return dp[n];
    }

private:
    TreeNode *getLeaf(TreeNode *node)
    {
        if (!node)
        {
            return nullptr;
        }
        return nullptr;
    }
};
