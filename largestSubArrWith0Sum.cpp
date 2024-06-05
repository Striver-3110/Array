//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

auto __init__ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

#pragma optimize("03");

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<long long int,vector<int>> mp;
        int maxDiff = 0;
        long long int sum = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                maxDiff = i+1;
            }
            mp[sum].push_back(i);
        }
        if( sum == 0){
            return n;
        }
        for(auto& pair : mp){
            vector<int> vec = pair.second;
           
            int temp = 0;
            
            if(vec[0] == 0 && pair.first == 0){
                temp = vec[vec.size()-1]-vec[0]+1;
            }else{
                temp = vec[vec.size()-1]-vec[0];
            }
            
            
            maxDiff = max(maxDiff,temp);

        }
        return maxDiff;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends