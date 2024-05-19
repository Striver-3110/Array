#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = n-1; i >= 0; i--){
            nums1[m+n-1-j] = nums2[i]; j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;
    int m, n, num;

    cout << "Enter the size of nums1 array (m): ";
    cin >> m;
    cout << "Enter the elements of nums1 array:" << endl;
    for(int i = 0; i < m; i++) {
        cin >> num;
        nums1.push_back(num);
    }

    cout << "Enter the size of nums2 array (n): ";
    cin >> n;
    cout << "Enter the elements of nums2 array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums2.push_back(num);
    }

    sol.merge(nums1, m, nums2, n);

    cout << "Merged and sorted array:" << endl;
    for(int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
