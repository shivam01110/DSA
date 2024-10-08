#include <bits/stdc++.h>
using namespace std;



int recurr(string& s, int i, int len, unordered_set<string>& dictionary, vector<int>& dp) {
    if (i >= len) return 0;
    if (dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    
    // Try every substring starting from index i
    for (int l = 1; l <= len - i; l++) {
        // No need to create substrings, just check using indices
        if (dictionary.find(s.substr(i, l)) != dictionary.end()) {
            ans = min(ans, recurr(s, i + l, len, dictionary, dp));
        } else {
            ans = min(ans, l + recurr(s, i + l, len, dictionary, dp));
        }
    }

    return dp[i] = ans;
}

int minExtraChar(string s, vector<string>& dictionary) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end()); // Faster lookups
    int len = s.length();
    vector<int> dp(len + 1, -1); // DP array initialized to -1
    return recurr(s, 0, len, dict, dp);
}