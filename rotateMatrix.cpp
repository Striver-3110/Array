#include <iostream>
#include <vector>
#include <algorithm> // For reverse

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //***************** better approach *************************
        // better logic to transpose the matrix
        int n = matrix.size();
        for(int i = 0; i < n; i++ ){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    int n, val;

    cout << "Enter the size of the square matrix: ";
    cin >> n;
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < n; i++) {
        vector<int> row;
        for(int j = 0; j < n; j++) {
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    sol.rotate(matrix);

    cout << "Rotated matrix:" << endl;
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
