//space->O(N) time->N*sqrt(max(nums1[i]))
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long, int> mp;
        long long cnt = 0;
        //1.preprocessing: store the freq of nums2[i]*k in map
        for (int j = 0; j < nums2.size(); ++j) {
            long long val = static_cast<long long>(nums2[j]) * k;
            mp[val]++;
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if(nums1[i]%k) continue;    //if nums1[i] is not divisible by k then skip to next iteration (Pruning)
            //check of factor of nums1[i] till sqrt(nums1[i])
            for(int div=1;div<=sqrt(nums1[i]);div++){
                if(nums1[i]%div==0){
                    //if f is a factor of n then n/f is also a factor of n
                    int f1=div,f2=nums1[i]/f1;
                    cnt+=mp[f1];
                    if(f1!=f2) cnt+=mp[f2];
                }
            }
        }
        return cnt;
    }
};