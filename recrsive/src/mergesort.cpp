#include <vector>
#include <iostream>

class Solution {
public:
    static void mergesort_ordered(const std::vector<int>& arr1,
                                  const std::vector<int>& arr2,
                                  std::vector<int>& res) {
        int i = 0;
        int j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                res.push_back(arr1[i]);
                ++i;
            } else {
                res.push_back(arr2[j]);
                ++j;
            }
        }

        for (; i < arr1.size(); ++i) {
            res.push_back(arr1[i]);
        }
        for (; j < arr2.size(); ++j) {
            res.push_back(arr2[j]);
        }
    }

    static void merge_sort(const std::vector<int>& input,
                           std::vector<int>& out) {

    }
};

int main() {
    const std::vector<int> arr1{1, 3, 4, 8, 10};
    const std::vector<int> arr2{2, 5, 9, 10, 11, 200};
    std::vector<int> res;
    res.reserve(arr1.size() + arr2.size());
    Solution::mergesort_ordered(arr1, arr2, res);
    for (const auto& item: res) {
        std::cout << item << " ";
    }
    return 0;
}
