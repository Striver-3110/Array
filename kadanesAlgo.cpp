#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : nums) {
            curMax = max(c, curMax + c);
            maxTillNow = max(maxTillNow, curMax);
        }
        return maxTillNow;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, num;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    int result = sol.maxSubArray(nums);

    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}


