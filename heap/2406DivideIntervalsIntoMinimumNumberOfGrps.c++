#include <bits/stdc++.h>
using namespace std;

int minGroups(vector<vector<int>>& intervals) {
    int n=intervals.size(),res=0;  
    sort(intervals.begin(),intervals.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1; //{end,room}
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(int i=0;i<n;i++){
        int s=intervals[i][0];
        int e=intervals[i][1];
        while(!pq1.empty() && pq1.top().first<s){
            pq2.push(pq1.top().second);
            pq1.pop();
        }
        if(pq2.empty()) pq2.push(pq1.size());
        pq1.push({e,pq2.top()});
        pq2.pop();
        res=max(res,(int)pq1.size());
    }
    return res;
}