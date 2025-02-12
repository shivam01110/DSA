#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recur(int i, int n, int op1, int op2, int k, vector<int>& nums, vector<vector<vector<int>>>& memo) {
        // Base case: If we have processed all elements
        if (i >= n) return 0;
        // Check if result is already computed
        if (memo[i][op1][op2] != -1) 
            return memo[i][op1][op2];
        // Initialize the result to a large value
        int res = INT_MAX;
        // Option 1: Use both op1 and op2 if possible
        if (op1 > 0 && op2 > 0) {
            if ((nums[i] + 1) / 2 >= k) {
                int cal = ((nums[i] + 1) / 2) - k;
                res = min(res, cal + recur(i + 1, n, op1 - 1, op2 - 1, k, nums, memo));
            }
            if (nums[i] >= k) {
                int cal = (nums[i] - k + 1) / 2;
                res = min(res, cal + recur(i + 1, n, op1 - 1, op2 - 1, k, nums, memo));
            }
        }
        // Option 2: Use only op1
        if (op1 > 0 && nums[i] > 0) {
            int cal = (nums[i] + 1) / 2;
            res = min(res, cal + recur(i + 1, n, op1 - 1, op2, k, nums, memo));
        }
        // Option 3: Use only op2
        if (op2 > 0 && nums[i] >= k) {
            int cal = nums[i] - k;
            res = min(res, cal + recur(i + 1, n, op1, op2 - 1, k, nums, memo));
        }
        // Option 4: Do nothing
        res = min(res, nums[i] + recur(i + 1, n, op1, op2, k, nums, memo));
        return memo[i][op1][op2] = res;
    }
    
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return recur(0, n, op1, op2, k, nums, memo);
    }
};