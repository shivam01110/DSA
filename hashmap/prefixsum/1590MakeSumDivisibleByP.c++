#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int len = nums.size();
        unordered_map<ll, int> sum;
        sum[0] = -1;  // To handle the case when we find the result from the beginning.
        ll tot = 0;
        for (int i = 0; i < len; i++) {
            tot += nums[i];
        }
        int rem = tot % p;
        if (rem == 0) return 0;  // Already divisible

        int minlen = INT_MAX;
        ll tot2 = 0;
        for (int i = 0; i < len; i++) {
            tot2 += nums[i];
            // Current prefix modulo
            int curr_mod = tot2 % p;

            // Required prefix modulo to remove the remainder `rem`
            int req_mod = (curr_mod - rem + p) % p;

            // Check if that prefix sum exists
            if (sum.count(req_mod)) {
                minlen = min(minlen, i - sum[req_mod]);
            }

            // Update the map with the current prefix mod
            sum[curr_mod] = i;
        }

        // If no subarray found
        if (minlen == INT_MAX || minlen == len) return -1;
        return minlen;
    }
};
