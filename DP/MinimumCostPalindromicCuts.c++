#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int minCostPalindromicCuts(string &s) {
    int n = s.length();
    
    // Step 1: Precompute palindrome table
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; i++) 
        isPalindrome[i][i] = true; // Single char is always a palindrome

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) isPalindrome[i][j] = true;
                else isPalindrome[i][j] = isPalindrome[i+1][j-1];
            }
        }
    }
    
    // Step 2: DP for minimum cuts and cost
    vector<int> cuts(n, INF);
    vector<int> cost(n, INF);

    for (int i = 0; i < n; i++) {
        if (isPalindrome[0][i]) { 
            cuts[i] = 0; // No cuts needed
            cost[i] = 0;
            continue;
        }

        for (int j = 0; j < i; j++) {
            if (isPalindrome[j+1][i]) { 
                int newCuts = cuts[j] + 1;
                int newCost = cost[j] + (s[j] + s[j+1]);

                if (newCuts < cuts[i] || (newCuts == cuts[i] && newCost < cost[i])) {
                    cuts[i] = newCuts;
                    cost[i] = newCost;
                }
            }
        }
    }

    return cost[n-1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << minCostPalindromicCuts(s) << endl;
    }
    return 0;
}
