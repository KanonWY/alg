#include "tree.h"

#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

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
        // std::cout << "delete node: " << root->value << std::endl;
        delete root;
        deleteTree(left);
        deleteTree(right);
    }
}

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
        // 如果是叶子节点则插入
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
    std::stack<TreeNode*> stack_nodes;
    stack_nodes.push(node);
    while (!stack_nodes.empty())
    {
        auto* topNode = stack_nodes.top();
        stack_nodes.pop();
        res.push_back(topNode->value);
        if (topNode->right)
        {
            stack_nodes.push(topNode->right);
        }
        if (topNode->left)
        {
            stack_nodes.push(topNode->left);
        }
    }
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
    std::vector<int> result;
    std::queue<TreeNode*> queue_nodes;
    queue_nodes.push(node);
    while (!queue_nodes.empty())
    {
        auto* curNode = queue_nodes.front();
        result.push_back(curNode->value);
        queue_nodes.pop();
        if (curNode->left)
        {
            queue_nodes.push(curNode->left);
        }
        if (curNode->right)
        {
            queue_nodes.push(curNode->right);
        }
    }
    return result;
}

void PrintTreeByLayer(TreeNode* node)
{
    if (!node)
    {
        return;
    }
    std::cout << "============================" << std::endl;
    std::queue<TreeNode*> queue_nodes;
    queue_nodes.push(node);
    while (!queue_nodes.empty())
    {
        auto* top = queue_nodes.front();
        queue_nodes.pop();
        std::cout << top->value << " ";
        if (top->left) queue_nodes.push(top->left);
        if (top->right) queue_nodes.push(top->right);
    }
    std::cout << std::endl;
    std::cout << "============================" << std::endl;
}

std::vector<int> midorderTravel(TreeNode* node)
{
    if (!node) return {};
    std::vector<int> result;
    std::stack<TreeNode*> stack_nodes;
    TreeNode* curNode = node;
    stack_nodes.push(node);
    while (!stack_nodes.empty())
    {
        // 找到最左边的节点位置
        while (curNode->left)
        {
            stack_nodes.push(curNode->left);
            curNode = curNode->left;
        }
        while (!stack_nodes.empty())
        {
            // 当前节点是当前栈顶的元素
            TreeNode* topNode = stack_nodes.top();
            stack_nodes.pop();
            result.push_back(topNode->value);
            if (topNode->right)
            {
                stack_nodes.push(topNode->right);
                curNode = topNode->right;
                break;
            }
        }
    }
    return result;
}

void midorderTravel(TreeNode* node, std::vector<int>& out)
{
    if (!node) return;
    midorderTravel(node->left, out);
    out.push_back(node->value);
    midorderTravel(node->right, out);
}

std::vector<int> postorderTravel(TreeNode* node)
{
    if (!node) return {};
    std::vector<int> result;
    std::stack<TreeNode*> stack_nodes;
    stack_nodes.push(node);
    while (!stack_nodes.empty())
    {
        TreeNode* curNode = stack_nodes.top();
        stack_nodes.pop();
        result.push_back(curNode->value);
        if (curNode->left) stack_nodes.push(curNode->left);
        if (curNode->right) stack_nodes.push(curNode->right);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void postorderTravel(TreeNode* node, std::vector<int>& out)
{
    if (!node) return;
    postorderTravel(node->left, out);
    postorderTravel(node->right, out);
    out.push_back(node->value);
}

std::vector<int> postorderTravel_no(TreeNode* node)
{
    if (!node) return {};
    std::vector<int> result;
    std::stack<TreeNode*> stack_nodes;
    stack_nodes.push(node);
    while (!stack_nodes.empty())
    {
        TreeNode* curNode = stack_nodes.top();
        stack_nodes.pop();
    }
    return result;
}

// int depthOfTree(TreeNode* node)
// {
//     if (!node) return 0;
//     return std::max(depthOfTree(node->left), depthOfTree(node->right)) + 1;
// }

int depthOfTree(TreeNode* node)
{
    return node
               ? 1 + std::max(depthOfTree(node->left), depthOfTree(node->right))
               : 0;
}
