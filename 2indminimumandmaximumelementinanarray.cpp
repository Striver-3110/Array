//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    pair<long long, long long> getMinMax(long long arr[], int n) {
        // code here
        int minI = n-1;
        int maxI = n-1;
        for(int i = 0; i < n; i++){
            if(arr[minI] > arr[i]){
                minI = i;
            }
            if(arr[maxI] < arr[i]){
                maxI = i;
            }
        }
        pair<long long, long long> p;
        p = {arr[minI],arr[maxI]};
        return p;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(a, n);
        
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends