#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto __init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        int n = nums.size() - 1;
        for(int i = n; i >= 1; i--){
            if(nums[i] > nums[i-1]){
                k = i-1;
                break;
            }
        }
        cout << k << " ";
        if(k == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int minI = -1;
        for(int i = k + 1; i <= n; i++){
            if(nums[k] < nums[i]){
                if(minI == -1){
                    minI = i;
                }
                else if(nums[minI] > nums[i]){
                    minI = i;
                }
            }
        }
        cout << minI << " ";
        if(k != -1)
            swap(nums[k], nums[minI]);
        
        sort(nums.begin() + k + 1, nums.end());
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

    cout << "Original permutation: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
