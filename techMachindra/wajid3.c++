#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // DP table initialization
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    // Populate the DP table
    for (int len = 2; len <= n; len++) { // len is the length of the subarray
        for (int i = 0; i <= n - len; i++) { // i is the starting index of the subarray
            int j = i + len - 1; // j is the ending index of the subarray
            dp[i][j] = v[i] * v[j];

            // Add the previous DP values for longer subarrays if they exist
            if (i + 1 <= j - 1) {
                dp[i][j] += dp[i + 1][j - 1];
            }
        }
    }
    // Find the maximum value in the dp table
    long long maxi = 0LL;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            maxi = max(maxi, dp[i][j]);
        }
    }
    cout << maxi << endl;
    return 0;
}