#pragma optimize("03", "unroll-loops");

auto _init_ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                 }
            }
        }

        for(int i = 0; i < m; i++){
            if(row[i] == 1){
                for(int j = 0; j < n ; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(col[j] == 1){
                for(int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }




        // int m = matrix.size();
        // int n = matrix[0].size();
        // // vector<vector<bool>> flg(m,vector<bool>(n,false));

        // vector<bool> row(m, false);
        // vector<bool> col(n, false);
        // vector<vector<int>> ans(m, vector<int>(n, 1));

        // // for(int i = 0; i < n; i++){
        // //     for(int j = 0; j < n;j++){
        // //         flg[i][j] = false;
        // //     }
        // // }

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (matrix[i][j] == 0) {
        //             if (!col[j]) { // column not set to zero
        //                 for (int k = 0; k < m; k++) {
        //                     ans[k][j] = 0;
        //                     col[j] = true;
        //                 }
        //             }
        //             if (!row[i]) {
        //                 for (int k = 0; k < n; k++) {
        //                     ans[i][k] = 0;
        //                 }
        //                 row[i] = true;
        //             }
        //         }
        //     }
        // }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (ans[i][j] == 0) {
        //             matrix[i][j] = ans[i][j];
        //         }
        //     }
        //     // cout<<endl;
        // }
    }
};
