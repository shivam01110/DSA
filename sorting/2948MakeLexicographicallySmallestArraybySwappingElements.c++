#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(make_pair(nums[i],i));
        }
        sort(a.begin(),a.end());
        vector<int> ele(n),ind(n),res(n);
        for(int i=0;i<n;i++){
            ele[i]=a[i].first;
            ind[i]=a[i].second;
        }
        int l=0;
        while(l<n){
            int r=l;
            while(r<n && abs(ele[r]-ele[max(l,r-1)])<=limit){
                r++;
            }
            sort(ind.begin()+l,ind.begin()+r);
            for(int i=l;i<r;i++){
                res[ind[i]]=ele[i];
            }
            l=r;
        }
        return res;
    }   
};