#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int n = 0, m = 0; // n = size of target array, m = size of nums array

    // Function to precompute LCM values for all subsets of the `target` array
    void computeLCM(vector<int>& target, vector<ll>& precomputeLCM) {
        for (int i = 1; i < (1 << n); i++) { // Iterate over all subsets of `target`
            precomputeLCM[i] = 1;  // Initialize LCM of the subset to 1
            int j = i, shift = 0; // j keeps track of subset, shift keeps index
            while (j > 0) {  // Iterate over bits to find elements in the subset
                if (j & 1) {  // If the bit is set, include this element in LCM
                    precomputeLCM[i] =(ll) (precomputeLCM[i] * target[shift]) / 
                                       __gcd(precomputeLCM[i],(ll) target[shift]);
                }
                j = j >> 1;  // Move to the next bit
                shift += 1;  // Move to the next element in the `target` array
            }
        }
    }

    // Memoization function to find the minimum increments needed
    ll memo(int ind, int mask, vector<int>& nums, vector<vector<ll>>& dp, vector<ll>& precomputeLCM) {
        if (mask == (1 << n) - 1) return 0;  // If all subsets are considered, return 0
        if (ind == m) return 1e9;  // If all elements in `nums` are exhausted, return large value
        if (dp[ind][mask] != -1) return dp[ind][mask];  // Return cached result if computed

        // Case 1: Skip the current `nums[ind]`
        ll minOperation = memo(ind + 1, mask, nums, dp, precomputeLCM);

        // Case 2: Try taking `nums[ind]` and adjusting it to match an LCM subset
        for (int i = 1; i < (1 << n); i++) {  // Iterate over all subsets of `target`
            ll currLCM = precomputeLCM[i];  // Get the LCM of the current subset

            // Calculate the required increments to make `nums[ind]` a multiple of `currLCM`
            ll reqOp = (nums[ind] % currLCM == 0) ? 0 : (currLCM - (nums[ind] % currLCM));

            // Update the minimum operations needed
            minOperation = min(minOperation, reqOp + memo(ind + 1, mask | i, nums, dp, precomputeLCM));
        }

        return dp[ind][mask] = minOperation;  // Store and return the computed value
    }

    // Main function to compute the minimum increments required
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        n = target.size(), m = nums.size();
        vector<ll> precomputeLCM(1 << n, 1);  // Array to store LCM of all subsets
        computeLCM(target, precomputeLCM);  // Compute LCMs of all subsets

        vector<vector<ll>> dp(m, vector<ll>(1 << n, -1));  // DP table for memoization
        return memo(0, 0, nums, dp, precomputeLCM);  // Start recursion from index 0 with an empty mask
    }
};
