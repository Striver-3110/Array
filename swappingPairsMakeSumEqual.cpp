//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+m);
        long sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            // cout<<a[i]<<" ";
            sum1 += a[i];
        }
        for(int i = 0; i < m; i++){
            sum2 += b[i];
        }
        long sum = sum1 + sum2;
        if(sum % 2 == 1){
            return -1;
        }
        long diff = (sum1 - sum2)/2;
        
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(a[i] - b[j] == (int)diff){
                return 1;
            }else if(a[i] - b[j] < (int)diff){
                i++;
            }else{
                j++;
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends