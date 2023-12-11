#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

class Solution {
public:
    static std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& number) {
        std::vector<std::vector<int>> res;
        std::vector<int> item;
        // 先压入一个空集
        res.push_back(item);
        std::set<std::vector<int>> res_set;
        std::sort(number.begin(), number.end());
        helper(number, 0, item, res, res_set);
        return res;
    }

private:
    static void helper(std::vector<int>& number, int start, std::vector<int>& item, std::vector<std::vector<int>>& res,
                       std::set<std::vector<int>>& res_set) {
        if (number.size() == start) {
            return;
        }
        item.push_back(number[start]);
        if (res_set.find(item) == res_set.end()) {
            res.push_back(item);
            res_set.insert(item);
        }
        helper(number, start + 1, item, res, res_set);
        item.pop_back();
        helper(number, start + 1, item, res, res_set);
    }
};

int main() {
    std::vector<int> number{1, 2, 3, 3};
    Solution s;
    const auto& res = s.subsetsWithDup(number);
    for (const auto& line: res) {
        for (const auto& item: line) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
