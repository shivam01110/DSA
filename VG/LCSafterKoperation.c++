#include <bits/stdc++.h>
using namespace std;

int dp[101][101][201]; // DP table (assuming max string length 100 and k <= 200)

int solve(int i, int j, int k, string& lottery, string& winner) {
    if (i >= lottery.length() || j >= winner.length() || k < 0) 
        return 0;

    if (dp[i][j][k] != -1) 
        return dp[i][j][k];

    int ans = 0;

    if (lottery[i] == winner[j]) {
        ans = 1 + solve(i + 1, j + 1, k, lottery, winner);
    } else {
        // Move to next character in winner
        ans = max(ans, solve(i, j + 1, k, lottery, winner));

        // Move to next character in lottery
        ans = max(ans, solve(i + 1, j, k, lottery, winner));

        // Modify lottery[i] to match winner[j] if within k limit
        int diff = abs(winner[j] - lottery[i]);
        int changes = min(diff, 26 - diff);
        if (changes <= k) {
            ans = max(ans, 1 + solve(i + 1, j + 1, k - changes, lottery, winner));
        }
    }

    return dp[i][j][k] = ans;
}

int maxLCSWithOperations(string lotteryID, string winnerID, int k) {
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, k, lotteryID, winnerID);
}

int main() {
    string lotteryID, winnerID;
    int k;
    cin >> lotteryID >> winnerID >> k;

    cout << maxLCSWithOperations(lotteryID, winnerID, k) << endl;
    return 0;
}
