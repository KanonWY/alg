#include "tree.h"

#include <stack>
#include <queue>
#include <iostream>
#include <functional>

std::vector<TreeNode*> getLeaf(TreeNode* node)
{
    if (!node)
    {
        return {};
    }

    std::vector<TreeNode*> res;
    std::stack<TreeNode*> stack_nodes;
    stack_nodes.push(node);
    while (!stack_nodes.empty())
    {
        auto p = stack_nodes.top();
        stack_nodes.pop();

        if (p->right)
        {
            stack_nodes.push(p->right);
        }
        if (p->left)
        {
            stack_nodes.push(p->left);
        }

        if (!p->left && !p->right)
        {
            res.push_back(p);
        }
    }
    return res;
}

void getleaf_recursive(TreeNode* node, std::vector<TreeNode*>& out)
{
    if (!node) return;
    if (!node->left && !node->right)
    {
        out.push_back(node);
    }
    getleaf_recursive(node->left, out);
    getleaf_recursive(node->right, out);
}

std::vector<int> preorderTravel(TreeNode* node)
{
    if (!node)
    {
        return {};
    }
    std::vector<int> res;
    
    return res;
}

void preorderTravel(TreeNode* node, std::vector<int>& out)
{
    if (node)
    {
        out.push_back(node->value);
        preorderTravel(node->left, out);
        preorderTravel(node->right, out);
    }
}

std::vector<int> layerTravel(TreeNode* node)
{
    if (!node)
    {
        return {};
    }
    std::vector<int> res;
    std::queue<TreeNode*> queue_nodes;
    queue_nodes.push(node);
    while (!queue_nodes.empty())
    {
        auto p = queue_nodes.front();
        res.push_back(p->value);
        queue_nodes.pop();
        if (p->left)
        {
            queue_nodes.push(p->left);
        }
        if (p->right)
        {
            queue_nodes.push(p->right);
        }
    }
    return res;
}

std::vector<int> midorderTravel(TreeNode* node)
{
    if (!node)
    {
        return {};
    }
    std::stack<TreeNode*> st;
    std::vector<int> res;
    TreeNode* currentNode = node;
    st.push(currentNode);
    while (!st.empty())
    {
        // 检测当前节点是否有左孩子
        while (currentNode->left != nullptr)
        {
            st.push(currentNode->left);
            currentNode = currentNode->left;
        }
        // 弹出栈顶（此时为左叶子节点）
        while (!st.empty())
        {
            const auto* topNode = st.top();
            st.pop();
            res.push_back(topNode->value);
            if (topNode->right != nullptr)
            {
                st.push(topNode->right);
                currentNode = topNode->right;
                break;
            }
        }
    }
    return res;
}

std::vector<int> postorderTravel(TreeNode* node)
{
    if (!node)
    {
        return {};
    }
    std::stack<TreeNode*> st;
    std::vector<int> res;
    const TreeNode* currentNode = node;
    st.push(node);

    while (!st.empty())
    {
        // 到达左叶子节点
        while (currentNode->left)
        {
            st.push(currentNode->left);
            currentNode = currentNode->left;
        }
        while (!st.empty())
        {
            const auto* topNode = st.top();
            // 当前节点存在右节点,将右节点压入栈内，优先处理右节点
            if (topNode->right)
            {
                st.push(topNode->right);
                break;
            }
            // 无右节点，插入到结果代码中
            res.push_back(topNode->value);
        }
    }
    return res;
}

std::vector<std::vector<int>> treepathOfSum(TreeNode* node, int target)
{
    if (!node)
    {
        return {};
    }
    std::vector<std::vector<int>> res;

    // lambda 递归函数, 必须使用 std::function 指明数据的类型
    std::function<void(TreeNode * node, int&, int, std::vector<int>&,
                       std::vector<std::vector<int>>&)>
        preorder = [&](TreeNode* node, int& path_value, int target,
                       std::vector<int>& path,
                       std::vector<std::vector<int>>& res) -> void {
        if (!node)
        {
            return;
        }
        path_value += node->value;
        path.push_back(node->value);
        if (!node->left && !node->right && path_value == target)
        {
            res.push_back(path);
        }
        preorder(node->left, path_value, target, path, res);
        preorder(node->right, path_value, target, path, res);
        path_value -= node->value;
        path.pop_back();
    };

    std::vector<int> path;
    int path_value{0};
    preorder(node, path_value, target, path, res);
    return res;
}

/**
 *          1
 *         / \
 *        2   3
 *      / \   / \
 *     4   5 6   7
 *
 *
 *
 * \brief
 * \return
 */
TreeNode* buildTree()
{
    auto* a = new TreeNode(1);
    auto* b = new TreeNode(2);
    auto* c = new TreeNode(3);
    auto* d = new TreeNode(4);
    auto* e = new TreeNode(5);
    auto* f = new TreeNode(6);
    auto* g = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    return a;
}

/**
 * \brief 前序遍历删除
 * \param root
 */
void deleteTree(TreeNode* root)
{
    if (root)
    {
        const auto left = root->left;
        const auto right = root->right;
        std::cout << "delete node: " << root->value << std::endl;
        delete root;
        deleteTree(left);
        deleteTree(right);
    }
}
