#include <string>
#include <vector>
#include <gtest/gtest.h>

// desc:
//      数字 n 代表生成括号的对数，请你设计一个函数，
//      用于能够生成所有可能的并且 有效的 括号组合。
class Solution
{
public:
    static std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> res;

        return res;
    }

private:
    void gen(std::string& item, int left, int right, int n,
             std::vector<std::string>& res)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(item);
        }

    }
};

TEST(recursive, generateParenthesis)
{
    EXPECT_EQ(32, 32);
    const auto res = Solution::generateParenthesis(4);
    EXPECT_EQ(res.size(), 10);
}
