//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#pragma optimize("03","unroll-loops")

auto __init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

#define pb(a) push_back(a)
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        vector<int> nar;
        vector<int> par;
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                nar.pb(arr[i]);
            }
            else{
                par.pb(arr[i]);
            }
        }
        int k = 0;
        for(int i = 0; i < par.size(); i++){
            arr[k++] = par[i];
        }
        for(int i = 0; i < nar.size(); i++){
            arr[k++] = nar[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends