#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums,int len){
        int l=0,r=0,tot=0,req=INT_MAX;
        for(;r<nums.size();r++){
            tot+=nums[r];
            if(r-l+1==len){
                if(tot>0){
                    req=min(req,tot);
                }
                tot-=nums[l];
                l++;
            }
        }
        if(req==INT_MAX) return -1;
        return req;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            int res=solve(nums,i);
            if(res!=-1) ans=min(ans,res);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};