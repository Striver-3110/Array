#include <iostream>
#include <vector>
#include <algorithm>

static int _ = []{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        std::vector<int> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1_1 = {1, 2, 2, 1};
    std::vector<int> nums1_2 = {2, 2};
    std::vector<int> result1 = sol.intersect(nums1_1, nums1_2);
    std::cout << "Intersection (example 1): ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2_1 = {4, 9, 5};
    std::vector<int> nums2_2 = {9, 4, 9, 8, 4};
    std::vector<int> result2 = sol.intersect(nums2_1, nums2_2);
    std::cout << "Intersection (example 2): ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums3_1 = {1, 2, 3, 4, 5};
    std::vector<int> nums3_2 = {2, 4, 6, 8};
    std::vector<int> result3 = sol.intersect(nums3_1, nums3_2);
    std::cout << "Intersection (example 3): ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
