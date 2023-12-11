#include <vector>
#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    explicit ListNode(const int x)
        :value(x), next(nullptr){}
};

void add_to_vector(const ListNode* header, std::vector<int>& vec) {
    if(!header) {
        return;
    }
    vec.push_back(header->value);
    add_to_vector(header->next,vec);
}

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    std::vector<int> res;
    add_to_vector(&a,res);
    for(const auto& item: res) {
        std::cout << item << "->";
    }
    return 0;
}
