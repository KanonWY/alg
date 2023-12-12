#include <iostream>
#include <vector>

/**
 * \brief 已知数组 nums, 求新数组 count, count[i] 表示再 nums[i] 右边，并且比nums[i] 小的元素的个数
 *
 *  nums[]  = { 3, 2, 1, 2, 10, 23, 8, 9};
 *  count[] = { 3, 1, 0, 0, 2,  2 , 0, 0};
 */
class Solution {
public:
    /**
     * \brief 时间复杂度为 o(N^2)
     * \param nums
     * \return
     */
    static std::vector<int> countSmaller_hardway(std::vector<int>& nums) {
        std::vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] < nums[i]) {
                    res[i]++;
                }
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums{3, 2, 1, 2, 10, 23, 8, 9};
    const auto res = Solution::countSmaller_hardway(nums);
    for(const auto& item : res) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}
