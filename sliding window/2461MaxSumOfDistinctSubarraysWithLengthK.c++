#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res=0,curr=0;
        unordered_map<int,int> m;
        int l=0,r=0,n=nums.size();
        while(r<n){
            //shirk the window while size of window > k or there already exist nums[r] in map
            while(l<r-k+1 || m[nums[r]]>=1){
                curr-=nums[l];
                m[nums[l]]=m[nums[l]]-1;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            curr+=nums[r];
            m[nums[r]]++;
            if(r-l+1==k){//if size of window is k
                res=max(res,curr);
            }
            r++;
        }
        return res;
    }
};