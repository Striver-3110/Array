//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

auto __init__ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int L[], int R[], int maxx) {
        // Your code here
        
        //********************************TLE********************************
        // BRUTEFORCE
        // TC --> O(n*maxx)
        // SC --> O(maxx)
        
        // map<int,int> mp;
        // int key = -1;
        // int maxFreq = -1;
        // for(int i = 0; i < n; i++){
        //     for(int j = l[i]; j <= r[i]; j++){
        //         mp[j]++;
        //     }
        // }
        // for(auto& pair: mp){
        //     // cout<<pair.first<<" "<<pair.second<<"\n";
        //     if(pair.second > maxFreq){
        //         maxFreq = pair.second;
        //         key = pair.first;
        //     }
        // }
        // return key;
        //****************************************************************
        
        // better + optimal
        // TC --> O(n + maxx)
        // SC --> O(maxx)
        
        vector<int> mp(maxx+2,0);
        for(int i = 0; i < n; i++){
            mp[L[i]]++;
        }
        for(int i = 0; i < n; i++){
            mp[R[i]+1]--;
        }
        int maxElem = INT_MIN;
        int maxIndex = 0;
        for(int i = 1; i <= maxx+1; i++){
            mp[i] = mp[i] + mp[i-1];
        }
        for(int i = 0; i <= maxx+1; i++){
            // maxElem = max(maxElem , mp[i])
            if(mp[maxIndex] < mp[i]){
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends