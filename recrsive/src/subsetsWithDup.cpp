#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

/*
 *  @brief 已知一组数（其中有重复的元素），求这组数可以组成的所有子集
 *
 *  nums[] = [2,1,2,2]
 *  [[],[1],[1,2],[1,2,2],[1,2,2,2],[2],[2,2],[2,2,2]]
 *  [2,1,2] ,[1,2,2]是重复
 */

/*
 *  [1,2,2,2]
 *  []
 *  [1]
 *  [2]
 *  [1,2]
 *  [2,2]
 *  [1,2,2]
 *  [2,2,2]
 *  [1,2,2,2]
 *
 *  可以使用一个 std::set 来过滤相同的序列
 */

class Solution {
public:
    std::vector<std::vector<int>> subsetWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        // 使用这个 set 来过滤重复的数组
        std::set<std::vector<int>> vector_set;
        std::vector<int> item;
        // 压入空
        res.push_back(item);
        generate(0,nums,item,vector_set,res);
        return res;
    }

private:
    static void generate(int start,
                         const std::vector<int>& nums,
                         std::vector<int>& item,
                         std::set<std::vector<int>>& vector_set,
                         std::vector<std::vector<int>>& result) {
        if (start >= nums.size()) {
            return;
        }
        item.push_back(nums[start]);
        if (vector_set.find(item) == vector_set.end()) {
            result.push_back(item);
            vector_set.insert(item);
        }
        generate(start + 1, nums, item, vector_set, result);
        item.pop_back();
        generate(start + 1, nums, item, vector_set, result);
    }
};

int main() {
    std::vector<int> vec{1,2,2,2};
    Solution s;
    const auto res = s.subsetWithDup(vec);
    for(const auto& line : res) {
        for(const auto& item: line) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}