#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    int n=nums.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({nums[i],i});
    }
    for(int i=0;i<k;i++){
        int ind=pq.top().second;
        nums[ind]=nums[ind]*multiplier;
        pq.pop();
        pq.push({nums[ind],ind});
    }
    return nums;
}