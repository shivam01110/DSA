#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int numMusicPlaylists(int n, int m, int k) {
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 1; // Base case: 1 way to create an empty playlist.

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= min(i, n); j++) {
            // Add a new song (must pick a song not used before)
            dp[i][j] = (dp[i - 1][j - 1] * (n - j + 1)) % MOD;
            
            // Replay an old song (only if we have more than k different songs already played)
            if (j > k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
            }
        }
    }

    return dp[m][n];
}

int main() {
    int n = 3, m = 3, k = 1;
    cout << numMusicPlaylists(n, m, k) << endl; // Output: 6
    cout << numMusicPlaylists(2,3,0) << endl; // Output: 6
    cout << numMusicPlaylists(2,3,1) << endl; // Output: 2
    return 0;
}
