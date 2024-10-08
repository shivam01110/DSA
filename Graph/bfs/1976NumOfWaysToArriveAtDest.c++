#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,ll>> adj[n];
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector<ll> cost(n,LLONG_MAX);
        vector<int> ways(n,0);
        cost[0]=0;
        ways[0]=1;
        set<pair<ll,int>> st;
        st.insert({0,0});
        while(!st.empty()){
            auto front=*(st.begin());
            st.erase(front);
            ll t=front.first;
            int u=front.second;
            for(auto v:adj[u]){
                if(cost[v.first]>t+v.second){
                    st.erase({cost[v.first],v.first});
                    cost[v.first]=t+v.second;
                    ways[v.first]=ways[u];
                    st.insert({cost[v.first],v.first});
                }
                else if(cost[v.first]==t+v.second) ways[v.first]=(ways[v.first]+ways[u])%mod;
            }
        }
        for(int i=0;i<n;i++){
            cout<<ways[i]<<" ";
        }
        return ways[n-1];
    }
};