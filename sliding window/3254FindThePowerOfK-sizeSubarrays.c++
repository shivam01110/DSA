#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n=nums.size();
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++){
            if(i==0 || nums[i]==nums[i-1]+1) prefix[i]=1;
        }
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+1;
        }
        vector<int> res;
        if(prefix[k-1]==k) res.push_back(nums[k-1]);
        else res.push_back(-1);
        for(int i=k;i<n;i++){
            if(prefix[i]-prefix[i-k]==k){
                res.push_back(nums[i]);
            }
            else res.push_back(-1);
        }
        return res;
    }
};