#include <bits/stdc++.h>
using namespace std;

long long find2rook(int r1,int c1,priority_queue<pair<int,pair<int,int>>> pq,bool& place){
    long long maxscore=LONG_MIN;
    while(!pq.empty()){
        int r2=pq.top().second.first;
        int c2=pq.top().second.second;
        if(r2!=r1 && c2!=c1){       //found second rook
            long long score2=pq.top().first;  //score for second rook
            pq.pop();
            priority_queue<pair<int,pair<int,int>>> pq2;
            bool rook3=false;
            while(!pq.empty() && !rook3){
                int r3=pq.top().second.first;
                int c3=pq.top().second.second;
                if(r3!=r1 && r3!=r2 && c3!=c2 && c3!=c1){   //found third rook
                    place=true;
                    rook3=true;
                    score2+=pq.top().first;
                }
                pq2.push(pq.top());
                pq.pop();
            }
            while(!pq2.empty()){
                pq.push(pq2.top());
                pq2.pop();
            }
            if(rook3) maxscore=max(maxscore,score2);
        }
        else pq.pop();
    }
    return maxscore;
}

long long maximumValueSum(vector<vector<int>>& board) {
    int m=board.size();
    int n=board[0].size();
    priority_queue<pair<int,pair<int,int>>> pq; //{score,{x,y}}
    for(int i=0;i<m;i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> top3; //top 3 score from each row;   {score,column}
        for(int j=0;j<n;j++){
            top3.push({board[i][j],j});
            if(j>2) top3.pop();
        }
        while(!top3.empty()){
            pq.push({top3.top().first,{i,top3.top().second}});
            top3.pop();
        }
    }
    long long res=LLONG_MIN;
    // long long res=0;
    while(!pq.empty()){
        int r1=pq.top().second.first;
        int c1=pq.top().second.second;
        long long score=pq.top().first;
        bool place=false;
        pq.pop();
        int s2=find2rook(r1,c1,pq,place);
        if(place) res=max(res,score+s2);
    }
    return res;
}

int main(){
    vector<vector<int>> board={{-24,-3,-64},{-13,-8,-74},{-23,-65,-99}};
    cout<<maximumValueSum(board)<<endl;
    return 0;
}