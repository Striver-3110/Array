//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        // int i = 0;
        // int j = 1;
        // int pair = 0;
        // while(i <= n-2 && j <= n-1){
        //     if(arr[i] + arr[j] == k){
        //         pair ++;
        //         j++;
        //         if(j == n){
        //             i++;
        //             j = i + 1;
        //         }
        //     }
        //     else if(j == n-1){
        //         i++;
        //         j = i+1;
        //     }
        //     else{
        //         j++;
        //     }
        // } 
        
        map<int,int> mp;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        int pair = 0;
        
        for(int i = 0; i < n; i++){
            int complement = k - arr[i];
            
            if(mp.find(complement) != mp.end()){
                if(complement == arr[i]){
                    pair += (mp[complement]-1);
                }
                else{
                    pair += (mp[complement]);
                }
            }
            
        }
        return pair/2;
        
    }
};


#pragma optimize("03","unroll-loops");

auto __init = [](){
    ios::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);
    return nullptr;
}();



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends