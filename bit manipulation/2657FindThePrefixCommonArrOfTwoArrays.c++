#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unsigned long long bitmask = 0; // 64-bit integer to represent a bitmask
        int n = A.size();
        vector<int> prefix(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // Process A[i]
            if (bitmask & (1ULL << (A[i] - 1))) { // Check if A[i] is already in the bitmask
                cnt++;
            } else {
                bitmask |= (1ULL << (A[i] - 1)); // Mark A[i] in the bitmask
            }

            // Process B[i]
            if (bitmask & (1ULL << (B[i] - 1))) { // Check if B[i] is already in the bitmask
                cnt++;
            } else {
                bitmask |= (1ULL << (B[i] - 1)); // Mark B[i] in the bitmask
            }

            prefix[i] = cnt; // Store the count of common elements
        }
        return prefix;
    }
};
