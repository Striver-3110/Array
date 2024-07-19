class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int> row_col_freq;

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            int min = INT_MAX;
            for(int j = 0; j < m; j++){
                min = std::min(matrix[i][j], min);
            }
            row_col_freq[min]++;
        }
        vector<int> ans;
        for(int i = 0; i < m; i++){
            int max = INT_MIN;
            for(int j = 0; j < n; j++){
                max = std::max(matrix[j][i], max);
            }
            row_col_freq[max]++;
            if(row_col_freq[max] == 2){
                ans.push_back(max);
            }
        }
        return ans;
    }
};