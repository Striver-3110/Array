#include <iostream>
#include <vector>

using namespace std;

auto __init__ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

#pragma optimize("03");

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;

        while(left != right){
            int mid = left + (right - left) / 2;
            int cnt = 0;

            for(auto num : nums){
                if(mid >= num){
                    cnt++;
                }
            }

            // 1 2 3 3 4 5 
            // here cnt will be 4 and mid = 3
            // hence we can say that only when the cnt > mid then 
            // the duplicate is present on the left half
            // else it is present on the right half
            if(cnt > mid){
                right = mid; // we have to include mid 
                // i.e. for test case 1 2 3 3
            } else {
                left = mid + 1; // we have to exclude mid in such case
                // i.e.
                //  1 2 3 4 5 5 in this case the mid will be 3 and the cnt = 3;
                // but the duplicate is not 3 at all
                // it is somewhat greater than mid
                // that is why we have excluded mid 
            }
        }
        return left;
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

    int duplicate = sol.findDuplicate(nums);

    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}
