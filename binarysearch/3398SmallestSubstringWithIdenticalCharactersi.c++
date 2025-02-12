#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if it is possible to transform the string `s` with `numOps` operations
    // such that the maximum length of repeating characters is at most `len`.
    bool isPossible(string s, int numOps, int len) {
        int n = s.length();
        int l = 0, r = 0;

        // Special case: If the allowed length `len` is 1, calculate the cost of alternating
        // the string and check if it's achievable within `numOps`.
        if (len == 1) {
            int op1 = 0, op2 = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2) { // Odd index
                    if (s[i] == '0') op1++;
                    if (s[i] == '1') op2++;
                } else { // Even index
                    if (s[i] == '1') op1++;
                    if (s[i] == '0') op2++;
                }
            }
            // Check if the number of operations needed is less than or equal to `numOps`
            return (op1 <= numOps || op2 <= numOps);
        }

        // General case: Check for maximum length of repeating characters
        int repeatChar = 0;
        for (int i = 0, lastCh = -1; i < n; i++) {
            if (s[i] == lastCh) { // Increment the count for consecutive characters
                repeatChar++;
            } else { // New character
                lastCh = s[i];
                // Subtract the required operations to split the repeating characters into chunks
                numOps -= (repeatChar / (len + 1));
                repeatChar = 1; // Reset the count for the new character
            }
        }
        // Process the last remaining  repeating characters
        numOps -= (repeatChar / (len + 1));

        // If the required operations are less than or equal to `numOps`, return true
        return (numOps >= 0);
    }

    // Function to find the minimum value of `len` such that the transformation is possible
    int minLength(string s, int numOps) {
        int h = s.length(), l = 1;
        int res = 0;

        // Perform binary search on the possible values of `len`
        while (l <= h) {
            int mid = (l + h) / 2; // Middle value of the search range
            if (isPossible(s, numOps, mid)) {
                res = mid; // Update result if transformation is possible
                h = mid - 1; // Search in the left half for a smaller `len`
            } else {
                l = mid + 1; // Search in the right half for a valid `len`
            }
        }
        return res; // Return the minimum possible `len`
    }
};
