#include "linklist.h"
#include <cstddef>
#include <iostream>


/*
 *
 *   [3, 4, ,5 ,6 ,7]
 *    0  1   2  3  4
 *    size = 5
 *
 *    3->4->5->6->7->nullptr
 *
 *
 */

ListNode* createListByVector(const std::vector<int>& input) {
    if (input.empty()) {
        return nullptr;
    }
    size_t    index = 0;
    ListNode* head  = new ListNode(input[index]);
    index++;
    ListNode* tmp = head;

    while (index < input.size()) {
        ListNode* n = new ListNode(input[index]);
        tmp->next   = n;
        tmp         = tmp->next;
        index++;
    }
    return head;
}


void FreeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head          = head->next;
        delete tmp;
        tmp = nullptr;
    }
}

void PrintLinkList(ListNode* head) {
    while (head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

size_t lengthOfLinkList(ListNode* head) {
    size_t len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}
