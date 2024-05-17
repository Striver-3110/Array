#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &A) {
        int xr = 0;
        int n = A.size();
        for(int i = 0; i < n; i++){
            xr = xr ^ A[i];
            xr ^= (i+1);
        }
        
        int oneBit = 0;
        while(!(xr & (1 << oneBit))){
            oneBit++;
        }
        
        int oneBitSetXor = 0;
        int oneBitNotSetXor = 0;
        
        for(int i = 0; i < n; i++){
            if(A[i] & (1 << oneBit)){
                oneBitSetXor ^= A[i];
            }else{
                oneBitNotSetXor ^= A[i];
            }
        }
        for(int i = 1; i <= n; i++){
            if(i & (1 << oneBit)){
                oneBitSetXor ^= i;
            }else{
                oneBitNotSetXor ^= i;
            }
        }
        int cnt = 0;
        for(auto& a: A){
            if(a == oneBitSetXor) cnt++;
        }
        int repeating;
        int missing;
        if(cnt == 2){
            repeating = oneBitSetXor;
            missing = oneBitNotSetXor;
        } 
        else{
            repeating = oneBitNotSetXor;
            missing = oneBitSetXor;
        }
        return {repeating, missing};
    }
};

int main() {
    Solution sol;
    vector<int> A, result;
    int n, num;

    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> num;
        A.push_back(num);
    }

    result = sol.repeatedNumber(A);

    cout << "Repeated number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}
