#include <bits/stdc++.h>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    int d=0;
    int distance=0;
    int x=0,y=0;
    set<pair<int,int>> s;
    for(auto obs:obstacles){
        s.insert({obs[0],obs[1]});
    }    
    for(auto com:commands){
        if(com==-2){
            d=(d-1+4)%4;        //turn left
        }
        else if(com==-1){
            d=(d+1)%4;          //turn right
        }
        else{
            for(int i=0;i<com;i++){
                if(s.find({x+dir[d][0],y+dir[d][1]})!=s.end()) break;
                x+=dir[d][0];
                y+=dir[d][1];
                distance=max(distance,int(pow(x,2)+pow(y,2)));
            }
        }
    }
    return distance;
}