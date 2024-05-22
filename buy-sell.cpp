#include <iostream>
#include <vector>
#include <algorithm> // For min, max_element
#include <climits>   // For INT_MAX

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];

        // Find the minimum price encountered so far
        for(int i = 0; i < n; i++) {
            mini = min(mini, prices[i]);
            prices[i] -= mini; // Update prices to reflect the profit if sold at this price
        }
        // Return the maximum profit from the updated prices
        return *max_element(prices.begin(), prices.end());
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    int n, price;

    cout << "Enter the number of days: ";
    cin >> n;
    cout << "Enter the prices for each day: ";
    for(int i = 0; i < n; i++) {
        cin >> price;
        prices.push_back(price);
    }

    int max_profit = sol.maxProfit(prices);

    cout << "The maximum profit that can be achieved is: " << max_profit << endl;

    return 0;
}
