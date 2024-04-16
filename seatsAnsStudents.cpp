#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC --> O(nlogn)
    // SC --> O(1)
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = students.size();
        int moves = 0;
        for (int i = 0; i < n; i++) {
            moves += abs(students[i] - seats[i]);
        }
        return moves;
    }
};

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Number of seats/students
        vector<int> seats(n), students(n);
        for (int i = 0; i < n; i++) {
            cin >> seats[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> students[i];
        }
        Solution ob;
        cout << ob.minMovesToSeat(seats, students) << endl;
    }
    return 0;
}
