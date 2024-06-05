//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int A[], int n) {
        
        int sum = 0;
        int res = 0;
        int maxi = 0;
        for(int i = 0 ; i< n ; i++)
        {
        res = res + A[i]*i;
        sum = sum + A[i];
        }
        for(int i = 0 ; i< n ; i++)
        {
            res = res + A[i]*n - sum;
           maxi = max(res , maxi);
        }
        return maxi;


    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends