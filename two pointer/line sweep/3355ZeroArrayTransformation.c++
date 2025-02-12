#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int,int> m;
        for(auto q:queries){
            m[q[0]]++;
            m[q[1]+1]--;
        }
        int n=nums.size();
        auto it=m.begin();
        int s=it->first,dec=it->second;
        for(int i=0;i<s;i++){
            if(nums[i]>0) return false;
        }
        it++;
        while(it!=m.end()){
            int e=it->first;
            int maxi=INT_MIN;
            for(int i=s;i<e;i++){
                maxi=max(nums[i],maxi);
                if(maxi>dec) return false;
            }
            s=e;
            dec+=it->second;
            it++;
        }
        for(int i=s;i<n;i++){
            if(nums[i]>0) return false;
        }
        return true;
    }
};