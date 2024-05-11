#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& a: nums) {
            mp[a]++;
        }
        vector<int> ans;
        int n = nums.size();

        for(const auto& pair : mp) {
            if(pair.second > n/3) {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums, result;
    int n, num;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    result = sol.majorityElement(nums);

    cout << "Majority elements: ";
    for(auto& ele : result) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
