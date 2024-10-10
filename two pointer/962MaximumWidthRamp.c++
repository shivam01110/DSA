#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> GreaterFromRight(n,-1);
        GreaterFromRight[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            GreaterFromRight[i]=max(nums[i],GreaterFromRight[i+1]);
        }
        int l=0,r=0,res=0;
        for(;l<n && r<n;l++){
            while(r<n && nums[l]<=GreaterFromRight[r]) r++;
            res=max(res,r-l-1);
        }
        return res;
    }
};