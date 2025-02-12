#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int res=0;
        int parityN=n%2;
        int parityM=m%2;
        for(int i=0;i<max(n,m);i++){
            if(i<n && parityM) res=res^(nums1[i]);
            if(i<m && parityN) res=res^(nums2[i]);
        }
        return res;
    }
};