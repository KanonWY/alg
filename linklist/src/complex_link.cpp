#include <utility>
#include <vector>
#include <map>
#include <gtest/gtest.h>


struct ComplexListNode {
    int              m_value;
    ComplexListNode* m_next;
    ComplexListNode* m_ramdom;
    ComplexListNode(int val):
        m_value(val), m_next(nullptr), m_ramdom(nullptr) {}
};


void freeComplexListNode(ComplexListNode* head) {
    while (head) {
        ComplexListNode* tmp = head;
        head                 = head->m_next;
        delete tmp;
    }
}

std::vector<std::pair<int, int>> getComplexListNode(ComplexListNode* node) {
    std::vector<std::pair<int, int>> res;

    while (node) {
        res.emplace_back(node->m_value, node->m_ramdom->m_value);
        node = node->m_next;
    }
    return res;
}


/**
 *
 *
 *    5 -> 4 -> 6 -> 8 -> 10 -> tail
 *
 *    1. 构造出 node
 *    2.
 *
 *
 *
 */


class Solution {
public:
    ComplexListNode* Clone(ComplexListNode* head) {
        if (!head) {
            return nullptr;
        }

        ComplexListNode*                tmp = head;
        std::map<ComplexListNode*, int> index_map;
        size_t                          index = 0;
        std::vector<ComplexListNode*>   res;
        while (tmp) {
            index_map[tmp] = index;
            res.emplace_back(new ComplexListNode(tmp->m_value));
            tmp = tmp->m_next;
            index++;
        }

        tmp   = head;
        index = 0;
        while (tmp && index < res.size() - 1) {
            res[index]->m_next   = res[index + 1];
            res[index]->m_ramdom = res[index_map[tmp->m_ramdom]];

            index++;
            tmp = tmp->m_next;
        }
        res[index]->m_ramdom = res[index_map[tmp->m_ramdom]];

        return res[0];
    }

    ComplexListNode* Clone_no_space(ComplexListNode* head) {
        if (!head) {
            return nullptr;
        }
        return head;
    }
};


TEST(LinkList, ComplexListNode) {
    EXPECT_EQ(1, 1 * 1);
    // build ComplexListNode
    auto* a   = new ComplexListNode(1);
    auto* b   = new ComplexListNode(2);
    auto* c   = new ComplexListNode(3);
    auto* d   = new ComplexListNode(4);
    auto* e   = new ComplexListNode(5);
    auto* f   = new ComplexListNode(6);
    auto* g   = new ComplexListNode(7);
    a->m_next = b;
    b->m_next = c;
    c->m_next = d;
    d->m_next = e;
    e->m_next = f;
    f->m_next = g;

    a->m_ramdom = g;
    b->m_ramdom = f;
    c->m_ramdom = e;
    d->m_ramdom = d;
    e->m_ramdom = c;
    f->m_ramdom = b;
    g->m_ramdom = a;

    Solution s;
    auto*    newheade = s.Clone(a);

    EXPECT_EQ(getComplexListNode(a), getComplexListNode(newheade));

    freeComplexListNode(newheade);
    freeComplexListNode(a);
}


TEST(LinkList, ComplexListNode2) {
    EXPECT_EQ(1, 1 * 1);
    // build ComplexListNode
    ComplexListNode* a = nullptr;
    Solution         s;
    auto*            newheade = s.Clone(a);

    EXPECT_EQ(getComplexListNode(a), getComplexListNode(newheade));

    freeComplexListNode(newheade);
    freeComplexListNode(a);
}
