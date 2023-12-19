
#include <sys/select.h>
#include <vector>


struct ListNode {
    ListNode* next{ nullptr };
    int       value;
    ListNode(int val):
        value(val), next(nullptr) {}
};


/**
 *\ brief 使用vector 的数据创建一个单向链表
 *
 */
ListNode* createListByVector(const std::vector<int>& input);

/**
 *\ brief 释放一个链表
 *
 */
void FreeList(ListNode* head);


/**
 *
 *\ brief 打印链表
 *
 */
void PrintLinkList(ListNode* head);


/**
 *\brief 获取链表的长度
 *
 */

size_t lengthOfLinkList(ListNode* head);
