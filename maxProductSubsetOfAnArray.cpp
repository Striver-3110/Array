//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


#define mod 1000000007

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int negMin = 10;
        int pos = 0;
        int neg = 0;
        bool zero = false;
        if(arr.size() == 1)return arr[0];
        
        for(auto &a: arr){
            if(a > 0)pos++;
            if(a < 0){
                negMin = min(negMin, abs(a));
                neg++;
            }
            if(a == 0) zero = true;
        }
        // cout<< negMin<< endl;
        if(pos == 0 && zero && neg == 0)return 0;
        if(neg == 1 && zero && pos == 0) return 0;
        
        long long mul = 1;
        if(neg & 1){// if neg are odd
            for(auto &a: arr){
                if(a != 0){
                    mul = (mul * a) % mod;
                }
            }
            return -(mul/negMin);
        }
        for(auto &a: arr){
            if(a != 0){
                mul = (mul * a) % mod;
            }
        }
        return mul;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends