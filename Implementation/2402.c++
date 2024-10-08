#include <bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(),meetings.end());
    int s=meetings.size();
    priority_queue<pi,vector<pi>,greater<pi>> pq;//min heap->{endTime,roomNo}
    vector<int> freq(n,0);
    queue<int> vacant;
    for(int i=0;i<n;i++){
        pq.push({0,i});
    }
    for(int i=0;i<s;i++){
        int endTime=pq.top().first;
        int room=pq.top().second;
        while(!pq.empty() && endTime<=meetings[i][0]){
            vacant.push(room);
            pq.pop();
            room=pq.top().second;
            endTime=pq.top().first;
        }
        while(!vacant.empty()){
            pq.push({0,vacant.front()});
            vacant.pop();
        }
        endTime=pq.top().first;
        room=pq.top().second;
        pq.pop();
        if(endTime>meetings[i][0]){
            endTime=endTime+meetings[i][1]-meetings[i][0];
            pq.push({endTime,room});
        }
        else{
            pq.push({meetings[i][1],room});
        }
        freq[room]++;
    }
    int ans=-1,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        cout<<i<<"-->"<<freq[i]<<endl;
        if(maxi<freq[i]){
            maxi=freq[i];
            ans=i;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> meetings={{18,19},{3,12},{17,19},{2,13},{7,10}};
    int n=4;
    cout<<mostBooked(n,meetings);
    return 0;
}