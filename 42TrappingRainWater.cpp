#include<bits/stdc++.h>
using namespace std;

// static int __star = []
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     return 0;
// }();
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        // int max = height[0];
        int i = 0;
        while (i < n && height[i] == 0)
        {
            i++;
        }
        if (i == n)
        {
            return 0;
        }
        int k = n - 1;
        // while(k > -1 && height[k] == 0 ){
        //     k--;
        // }
        // if(i == k || i > n-1){
        //     return 0;
        // }
        int maxEle = INT_MIN;
        int maxIndex = -1;
        for (int j = i; j <= k; j++)
        {
            if (maxEle <= height[j])
            {
                maxEle = height[j];
                maxIndex = j;
            }
        }
        int maxi = height[i];
        int ans = 0;
        for (i = i + 1; i < maxIndex; i++)
        {
            if (maxi <= height[i])
            {
                maxi = height[i];
                continue;
            }
            ans += maxi - height[i];
        }
        maxi = height[k];
        for (int j = k - 1; j > maxIndex; j--)
        {
            if (maxi <= height[j])
            {
                maxi = height[j];
                continue;
            }
            ans += maxi - height[j];
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example usage
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Call the trap method
    int result = solution.trap(height);

    // Output the result
    cout << "Amount of water trapped: " << result << endl;

    return 0;
}
