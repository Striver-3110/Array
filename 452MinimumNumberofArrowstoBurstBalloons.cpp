#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        std::sort(points.begin(), points.end(), [](const auto &a, const auto &b)
                  { return a[0] < b[0]; });

        int arrows = 1;
        int end = points[0][1];

        for (size_t i = 1; i < points.size(); ++i)
        {
            if (points[i][0] > end)
            {
                arrows++;
                end = points[i][1];
            }
            else
            {
                end = std::min(end, points[i][1]);
            }
        }

        return arrows;
    }
};

int main()
{
    Solution solution;

    // Example usage
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int minArrows = solution.findMinArrowShots(points);

    cout << "Minimum number of arrows required: " << minArrows << endl;

    return 0;
}
