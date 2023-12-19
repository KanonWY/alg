#include "linklist.h"
#include <gtest/gtest.h>
#include <vector>


TEST(linklist, base1) {
    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    ListNode*        head = createListByVector(vec);
    PrintLinkList(head);
    FreeList(head);
    // 注意 head 地址不能再使用了
}
