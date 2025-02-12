#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        // DP table: dp[i][j][k] => max profit at (i, j) with `k` robbers neutralized
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        // Base case: Starting point
        dp[0][0][0] = coins[0][0]; // steal or collect
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; // Neutralize the first robber
        }

        // Fill the DP table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i][j][k] == INT_MIN) continue;

                    // Move Right
                    if (j + 1 < n) {
                        int value = coins[i][j + 1];
                        // Case 1: Let the robber steal coins (if any)
                        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + value);
                        // Case 2: Neutralize the robber (if allowed)
                        if (value < 0 && k < 2) {
                            dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k]);
                        }
                    }

                    // Move Down
                    if (i + 1 < m) {
                        int value = coins[i + 1][j];
                        // Case 1: Let the robber steal coins (if any)
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + value);
                        // Case 2: Neutralize the robber (if allowed)
                        if (value < 0 && k < 2) {
                            dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k]);
                        }
                    }
                }
            }
        }

        // Find the maximum profit at (m-1, n-1) across all states
        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};

int main() {
    Solution sol;
    vector<vector<int>> coins = {
        {10, -5, 10},
        {-20, 5, 10},
        {10, -10, 10}
    };
    cout << sol.maxProfit(coins) << endl; // Example output
    return 0;
}
