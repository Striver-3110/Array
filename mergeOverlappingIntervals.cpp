#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // as intervals array should be sorted on the basis of first value
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();

        // as we are comparing i and i+1 values in intervals 
        // it is necessary to handle only one interval
        if(n == 1){
            return intervals;
        }

        vector<vector<int>> ans;
        int i = 0;
        while(i < n){
            // we will traverse through all n intervals even after comparing i and i+1 as we have attached 
            // short circuit operator before comparison
            int start = intervals[i][0];
            int end = intervals[i][1];
            // short circuit operator
            while(i < n - 1 && intervals[i+1][0] <= end){
                if(intervals[i+1][1] > end){
                    end = intervals[i+1][1];
                } else {
                    end = end;
                }
                i++;
            }
            // if comparison between i and i+1 returns true then we are incrementing i.
            // and when the comparison will return false i will be pointing on last combined interval
            // so we have to move to the next uncombined interval
            // that is why this is the second i++
            i++;
            
            ans.push_back({start, end});
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals, mergedIntervals;
    int n, start, end;

    cout << "Enter the number of intervals: ";
    cin >> n;

    cout << "Enter the intervals (start and end separated by space):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        intervals.push_back({start, end});
    }

    mergedIntervals = sol.merge(intervals);

    cout << "Merged intervals:" << endl;
    for(const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
