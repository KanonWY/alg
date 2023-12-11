#include <vector>
#include <iostream>


// subset
// 已知一组数（其中无重复）， 求这组苏剧可以组成的所有子集，结果中不可有重复的子集

// nums[] = [1,2,3]
// [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]

class Solution {
public:
   static std::vector<std::vector<int>> subset_noduplied(std::vector<int>& nums) {
       std::vector<std::vector<int>> res;
       std::vector<int> item;
       // 插入空集
       res.push_back(item);
       generate(0,nums,item,res);
       return res;
   }
private:
    static void generate(int start,
        const std::vector<int>& nums,
        std::vector<int>& item,
        std::vector<std::vector<int>>& result) {
        if(start >= nums.size()) {
            return;
        }
        // 进入此总是有效的
        item.push_back(nums[start]);
        result.push_back(item);
        generate(start+1,nums,item,result);
        // 解压出后面一个
        item.pop_back();
        generate(start+1, nums,item,result);
    }
};

int main() {
    std::vector<int> v{1,2,3};
    Solution s;
    auto res = s.subset_noduplied(v);
    std::cout << "===================>>>" << std::endl;
    for(const auto& line: res) {
        for(const auto& item : line) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "===================>>>" << std::endl;
    return 0;
}