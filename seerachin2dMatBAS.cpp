#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midRow = mid / n;
            int midCol = mid % n;

            if (matrix[midRow][midCol] == target) {
                return true;
            }
            if (matrix[midRow][midCol] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    int m, n, target, num;

    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> m >> n;

    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < m; i++) {
        vector<int> row;
        for(int j = 0; j < n; j++) {
            cin >> num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    cout << "Enter the target value to search: ";
    cin >> target;

    bool found = sol.searchMatrix(matrix, target);

    if(found) {
        cout << "Target value found in the matrix." << endl;
    } else {
        cout << "Target value not found in the matrix." << endl;
    }

    return 0;
}
