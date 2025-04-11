#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int n:nums){
            pq.push(n);
        }
        int operation=0;
        while(pq.top()<k){
            ll x=pq.top();
            pq.pop();
            ll y=pq.top();  
            pq.pop();
            ll in=x*2+y;
            pq.push(in);
            operation++;
        }
        return operation;
    }
};