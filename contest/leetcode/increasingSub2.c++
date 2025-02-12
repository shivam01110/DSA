#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int res=1;
        int prevlen=1;
        while(i<n){
            int maxi=INT_MIN;
            int l1=0;
            while(i<n && nums[i]>maxi){
                maxi=max(maxi,nums[i]);
                i++;
                l1++;
                res=max(res,l1/2);
            }
            res=max(res,min(prevlen,l1));
            maxi=INT_MIN;
            int l2=0;
            while(i<n && nums[i]>maxi){
                maxi=max(maxi,nums[i]);
                i++;
                l2++;
                res=max(res,l2/2);
            }
            res=max(res,min(l1,l2));
            prevlen=l2;
        }
        return res;
    }
};