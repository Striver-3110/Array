#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &arr, vector<int> &add)
    {
        int n = arr.size();
        vector<vector<int>> ans;
        int i = 0;
        while (i < n && add[0] > arr[i][1])
        {
            ans.push_back(arr[i]);
            i++;
        }
        while (i < n && add[1] >= arr[i][0])
        {
            add = {min(add[0], arr[i][0]), max(add[1], arr[i][1])};
            i++;
        }
        ans.push_back(add);
        while (i < n)
        {
            ans.push_back(arr[i]);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> new_interval = {2, 5};

    vector<vector<int>> result = sol.insert(intervals, new_interval);

    cout << "Resultant intervals after insertion:\n";
    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}