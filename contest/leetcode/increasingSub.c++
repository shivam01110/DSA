#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& nums,int i,int k){
        int maxi=INT_MIN;
        for(int j=i;j<i+k;j++){
            if(nums[j]<=maxi) return false;
            maxi=max(maxi,nums[j]);
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<=n-2*k;i++){
            if(solve(nums,i,k) && solve(nums,i+k,k)) return true;
        }
        return false;
    }
};