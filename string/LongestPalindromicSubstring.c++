#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubstring(string s) {
    int n = s.length();
    
    // Step 1: Transform the string
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    
    int m = t.length();
    vector<int> p(m, 0); // p[i] stores radius of palindrome centered at i
    int c = 0, r = 0, maxLen = 0;

    // Step 2: Apply Manacher’s Algorithm
    for (int i = 0; i < m; i++) {
        int mirror = 2 * c - i;  // Find the mirrored index of i

        if (i < r)
            p[i] = min(r - i, p[mirror]);

        // Expand around center i
        while (i + p[i] + 1 < m && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }

        // Update center and right boundary
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }

        // Update max palindrome length
        maxLen = max(maxLen, p[i]);
    }

    return maxLen; // Return longest palindrome length
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << longestPalindromicSubstring(s) << endl;
    return 0;
}
