#include "linklist.h"
#include <gtest/gtest.h>
#include <type_traits>
#include <vector>

// 获取两个链表相交的节点

/**
 *\brief 获取两个链表相交的节点
 *
 *    A -> B -> C -> D -> F -> Z -> K -> nullptr
 *           a      /|\         c
 *                   |
 *    H -> M -> G ->
 *               b
 *
 *    D 是交点
 *
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *l1 = headA, *l2 = headB;
        while (l1 != l2) {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        return l1;
    }
};

TEST(getIntersectionNode, haveNode) {
    // build linklist

    // a -> b -> c -> d -> e -> i -> j -> k -> nullptr
    //                   /
    // h -> g -> f   ---

    ListNode*              a = new ListNode(1);
    ListNode*              b = new ListNode(2);
    ListNode*              c = new ListNode(3);
    ListNode*              d = new ListNode(4);
    ListNode*              e = new ListNode(5);
    ListNode*              f = new ListNode(6);
    ListNode*              g = new ListNode(7);
    ListNode*              h = new ListNode(8);
    ListNode*              i = new ListNode(9);
    ListNode*              j = new ListNode(10);
    ListNode*              k = new ListNode(11);
    std::vector<ListNode*> resource;
    resource.push_back(a);
    resource.push_back(b);
    resource.push_back(c);
    resource.push_back(d);
    resource.push_back(e);
    resource.push_back(f);
    resource.push_back(g);
    resource.push_back(h);
    resource.push_back(i);
    resource.push_back(j);
    resource.push_back(k);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = i;
    i->next = j;
    j->next = k;

    h->next = g;
    g->next = f;
    f->next = e;


    // TEST logic
    Solution s;
    auto*    res = s.getIntersectionNode(a, h);
    std::cout << "====> " << res->value << std::endl;
    EXPECT_EQ(e, res);


    // free memory to heap
    for (auto* item: resource) {
        delete item;
        item = nullptr;
    }
}
