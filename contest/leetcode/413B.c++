#include <bits/stdc++.h>
using namespace std;


vector<int> resultsArray(vector<vector<int>>& queries, int k) {
    int n=queries.size();
    vector<int> res;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int dis=abs(queries[i][0])+abs(queries[i][1]);
        pq.push(dis);
        if(pq.size()>k) pq.pop();
        if(pq.size()==k){
            res.push_back(pq.top());
        }
        else{
            res.push_back(-1);
        }
    }
    return res;
}