#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& h) {
        int n = h.size();
        vector<int> hCorrected(n);
        for(int i = 0; i < n; i++){
            hCorrected[i] = h[i];
        }
        sort(hCorrected.begin(), hCorrected.end());
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(h[i] != hCorrected[i]){
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int result = solution.heightChecker(heights);
    cout << "Number of students in incorrect positions: " << result << endl;
    return 0;
}
