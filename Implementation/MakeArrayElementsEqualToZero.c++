#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int i,int d,int n,vector<int> nums){
        while(i>=0 && i<n){
            if(nums[i]>0){
                nums[i]--;
                d=(-1)*d;
            }
            i=i+d;
        }
        for(int x:nums){
            if(x>0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(isValid(i,1,n,nums)) cnt++;
            if(isValid(i,-1,n,nums)) cnt++;
        }
        return cnt;
    }
};