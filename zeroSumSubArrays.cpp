//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

auto __init__ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

#pragma optimize("03");


class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        unordered_map<long long int, int> mp;
        int sum = 0;
        long long int ans = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == 0)ans++;
            mp[sum]++;
        }
        
        for(auto& pair: mp){
            int val = pair.second;
            ans += (val*(val-1)/2);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends