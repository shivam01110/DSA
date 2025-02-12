#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minDifference(vector<int>& nums) {
        int mindiff=INT_MAX,maxdiff=INT_MIN;
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=-1 && nums[i-1]!=-1){
                mindiff=min(mindiff,abs(nums[i]-nums[i-1]));
                mindiff=min(mindiff,abs(nums[i]-nums[i-1]));
            }
        }
    }
};