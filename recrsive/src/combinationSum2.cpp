#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iostream>

/**
 * \brief 已知一组数（其中有重复的元素），求这组数可以组成的所子集中，子集中各个元素和为 target 的子集，结果中无重复的子集。
 */
class Solution {
public:
    static std::vector<std::vector<int>> combinationSum2(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::set<std::vector<int>> vector_set;
        std::vector<int> item;
        helper(0, target, item, nums, res, vector_set);
        return res;
    }

private:
    static void helper(int start, int target, std::vector<int>& item,
                       std::vector<int>& nums,
                       std::vector<std::vector<int>>& res,
                       std::set<std::vector<int>>& vector_set) {
        if (start >= nums.size() || std::accumulate(item.begin(), item.end(), 0) > target) {
            return;
        }

        item.push_back(nums[start]);
        if (vector_set.find(item) == vector_set.end() && std::accumulate(item.begin(), item.end(), 0) == target) {
            res.push_back(item);
            vector_set.insert(item);
        }
        helper(start + 1, target, item, nums, res, vector_set);
        item.pop_back();
        helper(start + 1, target, item, nums, res, vector_set);
    }
};

class Solution2 {
public:
    static std::vector<std::vector<int>> combinationSum2(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::set<std::vector<int>> vector_set;
        std::vector<int> item;
        helper(0, target, 0, nums, vector_set, item, res);
        return res;
    }

private:
    static void helper(int start, int target, int curSumValue,
                       std::vector<int>& nums,
                       std::set<std::vector<int>>& vector_set,
                       std::vector<int>& item,
                       std::vector<std::vector<int>>& res) {
        if (start >= nums.size() || curSumValue >= target) {
            return;
        }
        item.push_back(nums[start]);
        curSumValue += nums[start];
        if (vector_set.find(item) == vector_set.end() && curSumValue == target) {
            vector_set.insert(item);
            res.push_back(item);
        }
        helper(start + 1, target, curSumValue, nums, vector_set, item, res);
        curSumValue -= nums[start];
        item.pop_back();
        helper(start + 1, target, curSumValue, nums, vector_set, item, res);
    }
};


int main2() {
    Solution s;
    std::vector<int> nums{7, 2, 2, 3, 4, 5, 6, 1, 2, 2};
    const auto res = Solution::combinationSum2(nums, 7);
    for (const auto& line: res) {
        for (const auto& item: line) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}


int main() {
    Solution2 s;
    std::vector<int> nums{7, 2, 2, 3, 4, 5, 6, 1, 2, 2};
    const auto res = Solution2::combinationSum2(nums, 7);
    for (const auto& line: res) {
        for (const auto& item: line) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
