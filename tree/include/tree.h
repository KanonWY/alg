#pragma once

#include <vector>
#include <limits>
#include <stdexcept>
#include <atomic>
#include <iostream>

// 完全二叉树
// 假设二叉树的深度为 K, 除了 K 层之外，其他层的的节点数量达到最大层。
// 第 k 层的点集中在 最左边

// 满二叉树
// 每一层的节点都是满的
// 一个二叉树有 k 层， 节点数为 （2 ^ K - 1）

// 真二叉树
// 没有度为 1 的节点

// 基础
//
// 节点的度: 以该节点为父节点的子树的个数
//
//
// 叶子节点：度为 0 的节点
//
// 层数：根结点为第一层，根节点的子节点为第二层
//
// 节点的深度：从根据节点到当前节点位移路径上的节点总数
//
// 节点的高度：从当前节点开始到最远的叶子节点路径上的节点总数
//
// 树的深度：全部节点深度的最大值
//
// 树的高度：全部节点高度的最大值
//
// 树的深度等于高度

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int value;
    TreeNode(int v) : left(nullptr), right(nullptr), value(v) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : left(l), right(r), value(v) {}
};

std::vector<TreeNode*> getLeaf(TreeNode* node);

std::vector<int> preorderTravel(TreeNode* node);

std::vector<int> postorderTravel(TreeNode* node);

std::vector<int> midorderTravel(TreeNode* node);

std::vector<int> layerTravel(TreeNode* node);

int PathSumOfTree(TreeNode* root, int number);

// Temp request
constexpr int64_t LIMIT_SIZE = std::numeric_limits<int64_t>::max();
/**
 * @brief 限制实例化的数量
 *  实例化限制器，可以限制一个对象实例化的次数，用于限制某些资源的使用
 */

// 使用 CRTP 的模式限制实例化

template <typename T, size_t N = 200>
struct limited_instances
{
    inline static std::atomic<size_t> count{0};

    limited_instances()
    {
        if (count >= N)
        {
            throw std::logic_error("to many instances");
        }
        ++count;
    }
    ~limited_instances() { --count; }
};

template <typename D>
struct Base
{
    void interface_foo() { static_cast<D*>(this)->echo(); }
};

struct Der : public Base<Der>
{
    void echo() { std::cout << "Der" << std::endl; }
};

struct Der2 : public Base<Der2>
{
    void echo() { std::cout << "Der2" << std::endl; }
};

template <typename T>
void interface_echo(Base<T>& der)
{
    der.interface_foo();
}
