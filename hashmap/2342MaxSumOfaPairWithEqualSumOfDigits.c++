#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>> hash(82,vector<int>(2,0));
        for(int i=0;i<len;i++){
            int copy=nums[i],sum=0;
            while(copy){
                sum+=(copy%10);
                copy/=10;
            }
            hash[sum][0]=max(nums[i],hash[sum][0]);
            sort(hash[sum].begin(),hash[sum].end());
        }
        int ans=-1;
        for(int i=1;i<82;i++){
            if(hash[i][0]>0) ans=max(ans,hash[i][0]+hash[i][1]);
        }
        return ans;
    }
};