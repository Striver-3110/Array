//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        vector<int> ans;
        for(auto it : mp){
            if(it.second >= 2){
                ans.push_back(it.first);
            }
        }
        if(ans.size()){
            return ans;
        }
        return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends