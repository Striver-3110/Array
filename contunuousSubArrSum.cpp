#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool solve(vector<int>& nums,int i, int j,int sum, int k, vector<vector<bool>>& dp){
    //     if(i >= j){
    //         return false;
    //     }
    //     if(sum == 0){
    //         return dp[i][i] = true;
    //     }
    //     // if(sum < k){
    //     //     return false;
    //     // }
    //     if(sum % k == 0){
    //         return dp[i][i] = true;
    //     }
    //     if(dp[i][j]){
    //         return dp[i][j];
    //     }
    //     return dp[i][j] = solve(nums,i+1,j,sum-nums[i],k,dp) || solve(nums,i,j-1,sum-nums[j],k,dp);
    // }
    bool checkSubarraySum(vector<int>& nums, int k) {
        // ************************GIVES TLE************************************************
        // for(auto n: nums){
        //     sum += n;
        // }
        // vector<vector<bool>> dp(nums.size(),vector<bool>(nums.size(),false));
        // return solve(nums,0,nums.size()-1,sum,k,dp);



        // using the concept that
        // in some sum if we add some m that is divisible by k
        // then sum % k = (sum + m) % k;
        long long sum = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) == mp.end()){
                mp[rem] = i;
            }else{
                if(i-mp[rem] >=2){
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    
    bool result = solution.checkSubarraySum(nums, k);
    cout << (result ? "True" : "False") << endl; // Expected output: True

    vector<int> nums2 = {23, 2, 6, 4, 7};
    k = 13;
    
    result = solution.checkSubarraySum(nums2, k);
    cout << (result ? "True" : "False") << endl; // Expected output: False

    return 0;
}