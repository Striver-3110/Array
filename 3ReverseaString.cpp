//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string s)
    {
        // Your code goes here
        int len = s.length();
        // cout<<len;
        int low = 0;
        int high = len-1;
        
        while(low < high){
            char ch = s[low];
            s[low] = s[high];
            s[high] = ch;
            low++;
            high--;
        }
        return s;
        // return "";
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends