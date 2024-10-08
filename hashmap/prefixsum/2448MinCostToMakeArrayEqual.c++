#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    ll minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<int,int>> pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({nums[i],cost[i]});
        }
        // Sort the pairs based on the first element (the nums values)
        sort(pairs.begin(),pairs.end());
        // Left and right arrays to store the cumulative costs of changing values to the left or right
        vector<ll> left(n,0),right(n,0);
        ll leftSum=0,RightSum=0;
        for(int i=1;i<n;i++){
            // Compute the left cumulative cost
            // left[i] represents the cost to change all elements from 0 to i to the value at pairs[i].first
            leftSum+=pairs[i-1].second;     // Sum of costs for all elements before i
            left[i]=left[i-1]+(pairs[i].first-pairs[i-1].first)*(leftSum);
            // Compute the right cumulative cost
            // right[i] represents the cost to change all elements from i to n-1 to the value at pairs[i].first
            RightSum+=pairs[n-i].second;    // Sum of costs for all elements after n-i
            right[n-i-1]=right[n-i]+(pairs[n-i].first-pairs[n-i-1].first)*(RightSum);
        }
        // Now we calculate the minimum total cost (left + right for each position)
        ll MinCost=LLONG_MAX;
        for(int i=0;i<n;i++){
            MinCost=min(MinCost,left[i]+right[i]);
        }
        return MinCost;
    }
};