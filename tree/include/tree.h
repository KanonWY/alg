#pragma once
#include <vector>

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

/**
 *          1
 *         / \
 *        2   3
 *      / \   / \
 *     4   5 6   7
 *
 *    1 2 4 5 3 6 7
 *    4 2 5 1 6 3 7
 */

/**
 * \brief 构建一棵简单二叉树
 * \return
 */
TreeNode* buildTree();

/**
 *
 * \brief 前序遍历删除一棵树
 *
 */
void deleteTree(TreeNode* root);

/**
 * \brief 非递归的获取一棵二叉树的叶子节点
 * \param node
 * \return
 */
std::vector<TreeNode*> getLeaf(TreeNode* node);

/**
 * \brief 递归地获取一棵二叉树的叶子节点
 * \param node
 * \param out
 * \return
 */
void getleaf_recursive(TreeNode* node, std::vector<TreeNode*>& out);

/**
 * \brief 非递归的前序遍历树
 */
std::vector<int> preorderTravel(TreeNode* node);

/**
 * \brief 递归的前序遍历树
 *
 */
void preorderTravel(TreeNode* node, std::vector<int>& out);

/**
 * \brief 二叉树的层序遍历
 *  非递归则需要使用队列实现
 *  std::queue
 */
std::vector<int> layerTravel(TreeNode* node);

/**
 * \brief 层序打印
 *
 */
void PrintTreeByLayer(TreeNode* node);
/**
 * \brief 中序遍历
 */
std::vector<int> midorderTravel(TreeNode* node);

/**
 * \brief 递归中序遍历
 */
void midorderTravel(TreeNode* node, std::vector<int>& out);

/**
 * \brief 后序遍历
 */
std::vector<int> postorderTravel(TreeNode* node);

std::vector<int> postorderTravel_no(TreeNode* node);

/**
 *\brief 递归的后续遍历
 */
void postorderTravel(TreeNode* node, std::vector<int>& out);

//////////////////////////////////////////////////////////////////////////////////////

/**
 *\brief 求取一棵树的最大深度
 *
 */
int depthOfTree(TreeNode* node);

