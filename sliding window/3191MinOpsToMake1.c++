#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,ans=0;
        for(i=0;i<n-2;i++){
            if(nums[i]==1){
                continue;
            }
            else{
                ans++;
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
            }
        }
        if(nums[n-2]==0 || nums[n-1]==0) return -1;
        return ans;      
    }
};