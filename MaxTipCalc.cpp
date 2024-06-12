//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


struct Tip{
    int diff;
    int ind;
};

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<Tip> t(n);
        for(int i = 0; i < n; i++){
            t[i].ind = i;
            t[i].diff = abs(arr[i]-brr[i]);
        }
        sort(t.begin(),t.end(),[](const Tip &a,const Tip &b){return a.diff > b.diff;});
        
        long long tip = 0;
        for(int i = 0; i < n; i++){
            int index = t[i].ind;
            
            if(arr[index] > brr[index]){
                if(x > 0){
                    tip += arr[index];
                    x--;
                }
                else{
                    tip += brr[index];
                    y--;
                }
            }
            else{
                if(y > 0){
                    tip += brr[index];
                    y--;
                }
                else{
                    tip += arr[index];
                    x--;
                }
            }
        }
        return tip;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends