//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        int row;
        bool pal;
        for(row = 0; row < n; row++){
            int i = 0;
            int j = n-1;
            pal = true;
            while(i <= j){
                if(arr[row][i] == arr[row][j]){
                    i++;
                    j--;
                    
                    continue;
                }else{
                    pal = false;
                    break;
                }
            }
            if(pal){
                break;
            }
        }
        // cout<<row<<" ";
        if(row != n){
            return std::to_string(row) + " R";
        }
        int col = 0;
        for(col = 0; col < n; col++){
            int i = 0;
            int j = n-1;
            pal = true;
            while(i<=j){
                if(arr[i][col] == arr[j][col]){
                    i++;
                    j--;
                    continue;
                }
                else{
                    pal = false;
                    break;
                }  
            }
            if(pal){
                break;
            }
        }
        // cout<<col;
        if(col != n)
            return std::to_string(col)+" C";
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends