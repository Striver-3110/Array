//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
#define pb(a) push_back(a);
// #define int long long
class Solution{
    public:
    void swapInt(int *a, int *b){int temp = *a;*a = *b; *b = temp;}
    void swap(int * a, int * b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    vector<int> selectionSort(vector<int>arr, int n){
        for(int i = 0; i < n - 1; i++){
            int minI = i;
            for(int j = i + 1; j < n; j++){
                if(arr[j] < arr[minI]){
                    minI = j;
                }
            }
            if(minI != i){
                swap(&arr[i],&arr[minI]);
            }
        }
        return arr;
    }
    int partition(vector <int> & v, int s, int e){
        int lb = s;int ub = e;
        int pivot = v[s];
        while(lb < ub){
            while(v[lb] <= pivot && lb < e){lb++;}
            while(v[ub] > pivot && ub > s){ub--;}
            if(lb < ub) swapInt(&v[lb], &v[ub]);
        }
        swapInt(&v[s],&v[ub]);
            return ub;
    }
    void quickSort(vector<int>& v, int s, int e){
        if(s < e){
            int m = partition(v, s, e);
            quickSort(v, s, m - 1);
            quickSort(v, m + 1, e);
        }
    }
    void merge(vector<int>& arr, int s, int mid, int e){
        // lets have length of left sub array
        int n1 = mid - s + 1;
        
        // lets have length of right sub array
        int n2 = e - mid;
        
        vector<int> L,R;
        
        for(int i= 0 ; i < n1; i++){
            L.pb(arr[s+i]);
        }
        for(int j = 0; j < n2; j++){
            R.pb(arr[mid + 1 + j]);
        }
        
        
        int i = 0;
        int j = 0;
        
        int k = s;
        
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                arr[k++] = L[i++];
            }else{
                arr[k++] = R[j++];
            }
        }
        while(i < n1){
            arr[k++] = L[i++];
        }
        while(j < n2){
            arr[k++] = R[j++];
        }
        
    }
    
    
    void mergeSort(vector<int>& arr, int s, int e){
        if(s<e){
            int mid = s + (e-s)/2;
            mergeSort(arr,s,mid);
            mergeSort(arr,mid+1,e);
            merge(arr,s,mid,e);
        }
    }
    
    void insertionSort(vector<int>& arr, int n){
        
        for(int i = 1; i < n; i++){
            int temp = arr[i];
            int k = i-1;
            while(k>=0 && temp <= arr[k]){
                arr[k+1] = arr[k];
                k--;
            }
            arr[k+1] = temp;
        }
    }
    vector<int> sortArr(vector<int>arr, int n){
        // ##################################TLE################################
        
        
        // 1****************************************************************
        // using selectionSort
        // O(n2)
        // return selectionSort(arr,n);
        
        // 2****************************************************************
        // insertionSort(arr,n);
        // O(n2)
        // return arr;
        
        // ##################################TLE################################
        
        
        // 3****************************************************************
        // using quick sort
        // O(nlogn)
        quickSort(arr,0,n-1);
        return arr;
        
        // 4****************************************************************
        // using merge sort
        // O(nlogn)
        
        // mergeSort(arr,0,n-1);
        // return arr;
        
      
        
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends