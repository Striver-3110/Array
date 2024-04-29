//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        // it can esily be done by counting sort
        vector<int> C(3,0);
        
        for(int i = 0; i < n; i++){
            C[a[i]]++;
        }
        // cout<<C[0]<<" ";
        for(int i = 1; i < 3; i++){
            C[i] = C[i-1] + C[i];
            // cout<<C[i]<<" ";
        }
        
        vector<int> B(n);
        
        for(int i = n-1; i >= 0; i--){
            B[C[a[i]]-1] = a[i];
            C[a[i]]--;
        }
        
        for(int i = 0; i < n; i++){
            a[i] = B[i];
        }
        // cout<<endl;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends