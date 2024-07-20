#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum = 0;
        for (auto &a : colsum) {
            sum += a;
        }
        if (sum != upper + lower) return {};
        int m = colsum.size();

        vector<vector<int>> reconstructedMatrix(2, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (colsum[j] == 2) {
                reconstructedMatrix[0][j] = reconstructedMatrix[1][j] = 1;
                upper--;
                lower--;
                colsum[j] = 0;
            }
        }
        for (int j = 0; j < m; j++) {
            if (colsum[j] == 1) {
                if (upper > 0) {
                    reconstructedMatrix[0][j] = 1;
                    upper--;
                } else {
                    reconstructedMatrix[1][j] = 1;
                    lower--;
                }
            }
        }

        if (lower != 0 || upper != 0) return {};
        return reconstructedMatrix;
    }
};

int main() {
    Solution sol;

    int upper = 2;
    int lower = 3;
    vector<int> colsum = {2, 2, 1, 1};

    vector<vector<int>> result = sol.reconstructMatrix(upper, lower, colsum);

    if (result.empty()) {
        cout << "No valid matrix can be constructed." << endl;
    } else {
        cout << "Reconstructed Matrix:" << endl;
        for (const auto& row : result) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
