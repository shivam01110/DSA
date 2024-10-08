#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX,n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                int temp=nums[l]+nums[r];
                int sum=nums[i]+temp;
                if(diff>abs(sum-target)){
                    diff=abs(sum-target);
                    ans=sum;
                }
                if(temp==req){
                    return target;
                }
                else if(temp<req){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};