#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n;
        if(n < 0) nn = -(long)n;

        while(nn > 0) {
            if(nn % 2 == 1) {
                ans *= x;
            }
            x *= x;
            nn /= 2;
        }
        if(n < 0) return (double)(1.0) / ans;
        return ans;
    }
};

int main() {
    Solution sol;
    double x;
    int n;

    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of n: ";
    cin >> n;

    double result = sol.myPow(x, n);

    cout << "Result: " << result << endl;

    return 0;
}
