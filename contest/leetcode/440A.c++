#include <bits/stdc++.h>
using namespace std;


#define ll long long

class Solution {
public:
    vector<ll> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back(make_pair(nums1[i],nums2[i]));
        }
        sort(a.begin(),a.end());
        ll curr=0;
        unordered_map<int,ll> m;
        priority_queue<int,vector<int>,greater<int>> pq;
        m[a[0].first]=curr;
        for(int i=1;i<n;i++){
            pq.push(a[i-1].second);
            curr+=a[i-1].second;
            if(pq.size()>k){
                curr-=pq.top();
                pq.pop();
            }
            if(m.find(a[i].first)==m.end()){
                m[a[i].first]=curr;
            }
        }
        vector<ll> res(n);
        for(int i=0;i<n;i++){
            res[i]=m[nums1[i]];
        }
        return res;
    }
};