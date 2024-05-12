#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            } else if(el == nums[i]){
                cnt++;
            } else {
                cnt--;
            }
        }
        return el;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, num;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    int majority = sol.majorityElement(nums);

    cout << "Majority element: " << majority << endl;

    return 0;
}
