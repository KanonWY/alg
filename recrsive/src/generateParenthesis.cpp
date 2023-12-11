#include <string>
#include <vector>
#include <iostream>

using namespace std;

// desc:
//      数字 n 代表生成括号的对数，请你设计一个函数，
//      用于能够生成所有可能的并且 有效的 括号组合。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string item;
        helper(item, n, n, res);
        return res;
    }

private:
    void helper(std::string item, int left, int right, std::vector<std::string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(item);
            return;
        }

        if (left > 0) {
            helper(item + '(', left - 1, right, res);
        }
        if (right > left) {
            helper(item + ')', left, right - 1, res);
        }
    }
};

int main() {
    Solution s;
    const auto res = s.generateParenthesis(10);
    for (auto& item: res) {
        std::cout << item << std::endl;
    }
    std::cout << "res size = " << res.size() << std::endl;
    return 0;
}
