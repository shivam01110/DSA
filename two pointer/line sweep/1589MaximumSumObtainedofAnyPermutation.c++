#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        map<int,int> m;
        for(auto r:requests){
            m[r[0]]++;
            m[r[1]+1]--;
        }
        priority_queue<pair<int,int>> pq; //freq->times,i.e,keep the count of how many times a particular freq occurs
        auto it=m.begin();
        int prev=it->first,cnt=it->second;
        it++;
        for(;it!=m.end();it++){
            int times=(it->first)-prev;
            pq.push({cnt,times});
            prev=it->first;
            cnt+=it->second;
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());//sort the nums in descending order
        int i=0,tot=0;
        while (!pq.empty()){
            int freq=pq.top().first;
            int t=pq.top().second;
            while(t>0){
                tot=(tot+((ll)freq*(ll)nums[i])%mod)%mod;
                t--;
                i++;
            }
            pq.pop();
        }
        return tot;
    }
};