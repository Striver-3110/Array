#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) zeroes++;
            if(nums[i] == 1) ones++;
            if(nums[i] == 2) twos++;
        }

        int i = 0;
        while(zeroes--) {
            nums[i++] = 0;
        }
        while(ones--) {
            nums[i++] = 1;
        }
        while(twos--) {
            nums[i++] = 2;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, num;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements (only 0, 1, or 2): ";
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    sol.sortColors(nums);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
