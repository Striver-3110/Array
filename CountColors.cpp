#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;

        for(int i  = 0; i < nums.size(); i++){
            if(nums[i] == 0)zeroes++;
            if(nums[i] == 1)ones++;
            if(nums[i] == 2)twos++;
        }
        int i = 0;
        while(zeroes--){
            nums[i++] = 0;
        }
        while(ones--){
            nums[i++] = 1;
        }
        while(twos--){
            nums[i++] = 2;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    solution.sortColors(nums);
    
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}