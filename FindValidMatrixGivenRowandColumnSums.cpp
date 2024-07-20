#include <iostream>
#include <vector>
#include <algorithm> // For std::min

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> restoredMatrix(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                restoredMatrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= restoredMatrix[i][j]; 
                colSum[j] -= restoredMatrix[i][j];
            }
        }
        return restoredMatrix;
    }
};

int main() {
    Solution sol;

    vector<int> rowSum = {3, 8};
    vector<int> colSum = {4, 7};

    vector<vector<int>> result = sol.restoreMatrix(rowSum, colSum);

    cout << "Restored Matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
