#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, cntk = 0;
        // Count the occurrences of the target element `k` in the array
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) cntk += 1;
        }
        // Iterate through all possible values from 1 to 50 (constraints of nums[i])
        for (int i = 1; i < 51; i++) {
            int maxsum = 0, curr = 0; // maxsum stores the max gain for value `i`
            // Traverse the array to calculate the contribution of value `i`
            for (int j = 0; j < n; j++) {
                if (nums[j] == k) {
                    curr -= 1; // Decrease score if we encounter the target value `k`
                } 
                else if (nums[j] == i) {
                    curr += 1; // Increase score if we encounter the current value `i`
                } 
                else continue; // Skip if it's neither `k` nor the current value `i`
                // Ensure the current score doesn't drop below 0
                curr = max(0, curr);
                // Update the max gain for the current value `i`
                maxsum = max(maxsum, curr);
            }
            // Update the overall maximum frequency by adding the occurrences of `k`
            res = max(res, cntk + maxsum);
        }
        return res; // Return the maximum frequency achievable
    }
};
