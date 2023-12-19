#include "linklist.h"

/**
 *
 *    l1:
 *    1 -> 3 -> 5 -> 7 -> 9
 *
 *    l2:
 *    2 -> 4 -> 6 -> 8 -> 10 -> 11 -> 12 -> 13
 *
 *    mergedlink
 *    1 -> 2 - > 3 -> 4 ..... -> 13
 *
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHeader;
        ListNode* tmp;
        while (l1 && l2) {
            if (l1->value <= l2->value) {
                // create a new node to store the new element
            }
        }

        while (l1) {
        }

        return nullptr;
    }
};
