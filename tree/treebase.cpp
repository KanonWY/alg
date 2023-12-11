#include "tree.h"

#include <stack>
#include <queue>
#include <iostream>


std::vector<TreeNode *> getLeaf(TreeNode* node) {
    if (!node) {
        return {};
    }

    std::vector<TreeNode *> res;
    std::stack<TreeNode *> stack_nodes;
    stack_nodes.push(node);
    while (!stack_nodes.empty()) {
        auto p = stack_nodes.top();
        stack_nodes.pop();

        if (p->right) {
            stack_nodes.push(p->right);
        }
        if (p->left) {
            stack_nodes.push(p->left);
        }

        if (!p->left && !p->right) {
            res.push_back(p);
        }
    }
    return res;
}

std::vector<int> preorderTravel(TreeNode* node) {
    if (!node) {
        return {};
    }
    std::vector<int> res;
    std::stack<TreeNode *> stack_nodes;
    stack_nodes.push(node);
    while (!stack_nodes.empty()) {
        auto p = stack_nodes.top();
        stack_nodes.pop();
        res.push_back(p->value);
        if (!p->right) {
            stack_nodes.push(p);
        }
        if (!p->left) {
            stack_nodes.push(p);
        }
    }
    return res;
}

std::vector<int> layerTravel(TreeNode* node) {
    if (!node) {
        return {};
    }
    std::vector<int> res;
    std::queue<TreeNode *> queue_nodes;
    queue_nodes.push(node);
    while (!queue_nodes.empty()) {
        auto p = queue_nodes.front();
        res.push_back(p->value);
        queue_nodes.pop();
        if (p->left) {
            queue_nodes.push(p->left);
        }
        if (p->right) {
            queue_nodes.push(p->right);
        }
    }
    return res;
}

std::vector<int> midorderTravel(TreeNode* node) {
    if (!node) {
        return {};
    }
    std::stack<TreeNode *> st;
    std::vector<int> res;
    TreeNode* currentNode = node;
    st.push(currentNode);
    while (!st.empty()) {
        // 检测当前节点是否有左孩子
        while (currentNode->left != nullptr) {
            st.push(currentNode->left);
            currentNode = currentNode->left;
        }
        // 弹出栈顶（此时为左叶子节点）
        while (!st.empty()) {
            const auto* topNode = st.top();
            st.pop();
            res.push_back(topNode->value);
            if (topNode->right != nullptr) {
                st.push(topNode->right);
                currentNode = topNode->right;
                break;
            }
        }
    }
    return res;
}

std::vector<int> postorderTravel(TreeNode* node) {
    if (!node) {
        return {};
    }
    std::stack<TreeNode *> st;
    std::vector<int> res;
    const TreeNode* currentNode = node;
    st.push(node);

    while (!st.empty()) {
        // 到达左叶子节点
        while (currentNode->left) {
            st.push(currentNode->left);
            currentNode = currentNode->left;
        }
        while (!st.empty()) {
            const auto* topNode = st.top();
            // 当前节点存在右节点,将右节点压入栈内，优先处理右节点
            if (topNode->right) {
                st.push(topNode->right);
                break;
            }
            // 无右节点，插入到结果代码中
            res.push_back(topNode->value);
        }
    }
    return res;
}

int PathSumOfTree(TreeNode* root, int number) { return 0; }
