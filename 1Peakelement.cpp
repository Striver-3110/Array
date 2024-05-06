//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        
        int low = 0;
        int high = n-1;
        int mid = -1;
        
        if(n == 1){
            return 0;
        }
        if(arr[n-1] >= arr[n-2]){
            return n-1;
        }
        if(arr[0] >= arr[1]){
            return 0;
        }
        
        while(low < high){
            mid = low + (high-low)/2;
            
            if(arr[mid] <= arr[mid+1]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        // cout<<mid<<" "<<high;
        return high;
        
        
        
    // [1,2,3,4,5] =>  mid = ind(2) 
    // but is is less then the right element 
    // which means that the peak is in right half
    // again mid = ind()
       // Your code here
    //   if(n == 1){
    //       return 0;
    //   }
    
    //     if(arr[0] >= arr[1]){
    //         return 0;
    //     }if(arr[n-2] <= arr[n-1]){
    //         return n-1;
    //     }
       
    //   bool left = false,right = false;
       
    //   for(int i = 1; i < n-1 ; i++){
    //     //   if(i-1 >= 0){
    //           if(arr[i-1] <= arr[i]){
    //               left = !left;
    //           }
    //     //   }
    //     //   if(i+1 < n){
    //           if(arr[i] >= arr[i+1]){
    //               right = !right;
    //           }
    //     //   }
    //       if(right && left){
    //         //   cout<<i<<endl;
    //           return i;
    //       }
    //       right = false;
    //       left = false;
           
    //   }
    // //   cout<<-1<<endl;
    //   return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends