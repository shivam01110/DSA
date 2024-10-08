#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int maxi=INT_MIN;
    int res=0,len=nums.size();
    for(int i=0;i<len;i++){
        if(nums[i]>=maxi){
            int cnt=1;
            while(i<len-1 && nums[i]==nums[i+1]){
                i++;
                cnt++;
            }
            if(nums[i]==maxi)res=max(res,cnt);
            else res=cnt;
            maxi=nums[i];
        }
    }
    return res;
}
