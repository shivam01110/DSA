#include <bits/stdc++.h>
using namespace std;

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n=times.size();
    vector<pair<pair<int,int>,int>> tp; //{{start,end},index}
    for(int i=0;i<n;i++){
        tp.push_back({{times[i][0],times[i][1]},i});
    }
    sort(tp.begin(),tp.end());  //sort the tp on the basis of arrival time in ascending order
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1; //{endtime,chair}
    priority_queue<int,vector<int>,greater<int>> pq2;    //store the available smallest chair on the top
    for(int i=0;i<n;i++){
        int start=tp[i].first.first;
        int end=tp[i].first.second;
        int ind=tp[i].second;
        //remove all the friend from pq1 that will leave before the current arrival time and update the pq2 also
        while(!pq1.empty() && pq1.top().first<=start){
            pq2.push(pq1.top().second); //push free chair in pq2
            pq1.pop();
        }
        if(pq2.empty()) pq2.push(pq1.size());   //if pq2 is empty,all chair are occupied and next smallest chair number=number of already occupied chairs(i.e pq1.size())
        if(ind==targetFriend) return pq2.top();
        pq1.push({end,pq2.top()});
        pq2.pop();
    }
    return 0;
}