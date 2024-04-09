#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i-1] < nums[i]){
                continue;
            }
            ans += nums[i-1]-nums[i] + 1;
            nums[i] += nums[i-1]-nums[i] + 1;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    int result = solution.minIncrementForUnique(nums);
    cout << "Minimum increments needed: " << result << endl;
    return 0;
}
