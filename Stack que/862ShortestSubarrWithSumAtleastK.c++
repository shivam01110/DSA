#include <bits/stdc++.h>
using namespace std;
#define ll long long
int shortestSubarray(vector<int>& nums, int k) {
    int n=nums.size(),res=n+1;
    deque<pair<int,ll>> dq;
    dq.push_back({-1,0});   //intailly sum=0
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        //compress the window from the left side to get window of smaller size
        while(!dq.empty() && sum-dq.front().second>=k){
            res=min(res,i-dq.front().first);
            dq.pop_front();
        }
        //pop the element from the back side to maintain the monotonocity of the deque
        while(!dq.empty() && dq.back().second>=sum){
            dq.pop_back();
        }
        dq.push_back({i,sum});
    }
    if(res==n+1) return -1;
    return res;
}