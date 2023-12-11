#include "tree.h"
#include <stack>
#include <iostream>
#include <memory>

/**
 *          3
 *        /   \
 *       1     2
 *     /  \   /  \
 *    12   8  9   20
 *   /  \        /  \
 *  11   9      7    6
 *
 *   mid：  11 12 9 1 8 3 9 2 7 20 6
 *   post:
 **/

/**
 * @brief 创建一个新树
 */
TreeNode* BuildTree()
{
    auto* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(8);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    root->left->left->left = new TreeNode(11);
    root->left->left->right = new TreeNode(9);

    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(6);

    return root;
}

/**
 * @brief 删除一个树
 */
void DeleteTree(TreeNode* node)
{
    if (!node)
    {
        return;
    }

    std::stack<TreeNode*> st;
    st.push(node);
    while (!st.empty())
    {
        auto* topnode = st.top();
        st.pop();
        if (topnode->right)
        {
            st.push(topnode->right);
        }
        if (topnode->left)
        {
            st.push(topnode->left);
        }
        if (topnode)
        {
            std::cout << "释放 " << topnode->value << std::endl;
            delete topnode;
        }
    }
}

void printRes(const std::vector<int>& res)
{
    for (auto& item : res)
    {
        std::cout << item << "->";
    }
    std::cout << "none" << std::endl;
}

struct Logger : limited_instances<Logger>
{
    void echo() { std::cout << "hello" << std::endl; }
};

int main(int argc, char* argv[])
{
    std::vector<std::shared_ptr<Logger>> logs;
    for (int i = 0; i < 20; ++i)
    {
        std::cout << i << std::endl;
        logs.emplace_back(std::make_shared<Logger>());
    }

    return 0;
}
