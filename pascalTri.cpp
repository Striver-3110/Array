#include <iostream>
#include <vector>

using namespace std;

auto __init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas;
        vector<int> a {1};
        pas.push_back(a);
        if(numRows == 1){
            return pas;
        }
        for(int i = 1; i < numRows; i++){
            vector<int> x;
            x.push_back(1);
            int s = pas.size();
            int vecLen = pas[s-1].size();

            for(int j = 0; j < vecLen-1; j++){
                x.push_back(pas[s-1][j] + pas[s-1][j+1]);
            }

            x.push_back(1);
            pas.push_back(x);
        }
        return pas;
    }
};

int main() {
    Solution sol;
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for(const auto& row : result) {
        for(int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
