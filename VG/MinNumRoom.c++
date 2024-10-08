#include <bits/stdc++.h>
using namespace std;

int minRoom(vector<vector<int>> meeting){
    sort(meeting.begin(),meeting.end());
    int n=meeting.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;   //min heap for storing {endtime,roomno};
    priority_queue<int,vector<int>,greater<>> vacant;     //vacant room-->least room available
    int ans=0;
    for(int i=0;i<n;i++){
        while(!pq.empty() && pq.top().first<=meeting[i][0]){
            vacant.push(pq.top().second);
            pq.pop();
        }
        if(!vacant.empty()){
            pq.push({meeting[i][1],vacant.top()});
            vacant.pop();
        }
        else{
            ans++;
            pq.push({meeting[i][1],ans});
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> meeting={{0, 5}, {1, 2}, {6, 10}};
    cout<<minRoom(meeting)<<endl;
    return 0;
}