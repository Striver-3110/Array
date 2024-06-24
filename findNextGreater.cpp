#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int findGreater(vector<int>& nums, int ind) {
        for (int i = ind + 1; i < nums.size(); i++) {
            if (nums[ind] < nums[i]) {
                return nums[i];
            }
        }
        return -1;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> pos;
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++) {
            pos[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++) {
            int ind = pos[nums1[i]];
            int greater = findGreater(nums2, ind);
            ans.push_back(greater);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
