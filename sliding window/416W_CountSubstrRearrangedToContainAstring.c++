#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count if the window has all characters needed for word2
    bool isValid(const vector<int>& freq1, const vector<int>& freq2, int len2) {
        for (int i = 0; i < 26; ++i) {
            if (freq2[i] > 0 && freq1[i] < freq2[i]) {
                return false;  // freq1 should have at least as many as in freq2
            }
        }
        return true;
    }
    
    long long validSubstringCount(string word1, string word2) {
        int l = 0, r = 0;
        long long res = 0;
        int len2 = word2.size(), len1 = word1.size();
        
        vector<int> freq2(26, 0), freq1(26, 0);
        
        // Fill the frequency map for word2
        for (char c : word2) {
            freq2[c - 'a']++;
        }

        // Sliding window
        while (r < len1) {
            // Add the current character to the window
            freq1[word1[r] - 'a']++;
            
            // Check if the window is valid
            while (isValid(freq1, freq2, len2)) {
                // All substrings starting from `l` to `r` are valid, so add to result
                res += (len1 - r);  // Every suffix starting from r is valid
                // Shrink the window from the left
                freq1[word1[l] - 'a']--;
                l++;
            }
            
            // Move the right pointer
            r++;
        }

        return res;
    }
};
