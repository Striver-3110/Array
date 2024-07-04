#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

static int _ = []() { 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    return 0;
}();

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i <= 3; ++i) {
            ans = std::min(nums[(n - 1) - 3 + i] - nums[i], ans);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {5, 3, 2, 4};
    std::cout << "Min difference (example 1): " << sol.minDifference(nums1) << std::endl;

    std::vector<int> nums2 = {1, 5, 0, 10, 14};
    std::cout << "Min difference (example 2): " << sol.minDifference(nums2) << std::endl;

    std::vector<int> nums3 = {6, 6, 0, 1, 1, 4, 6};
    std::cout << "Min difference (example 3): " << sol.minDifference(nums3) << std::endl;

    std::vector<int> nums4 = {1, 5, 6, 14, 15};
    std::cout << "Min difference (example 4): " << sol.minDifference(nums4) << std::endl;

    return 0;
}
