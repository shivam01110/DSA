#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={-1,1,0,0};
    int IndexOfZERO(string str){
        for(int i=0;i<6;i++){
            if(str[i]=='0') return i;
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string curr="";
        string target="123450";
        for(auto row:board){
            for(auto i:row){
                curr+=to_string(i-0);
            }
        }
        unordered_map<string,int> vis;
        int moves=0;
        queue<string> q;
        vis[curr]=1;
        q.push(curr);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                string front=q.front();
                if(front==target) return moves;
                int CurrInd=IndexOfZERO(front);
                int r=CurrInd/3,c=CurrInd%3;    //row and col of 0
                //try all possible moves
                for(int p=0;p<4;p++){
                    int nr=r+dr[p],nc=c+dc[p];
                    if(0<=nr && nr<2 && 0<=nc && nc<3){
                        int newInd=nr*3+nc;
                        string newState=front;
                        swap(newState[CurrInd],newState[newInd]);
                        if(vis[newState]!=1){//if newState is not visited
                            q.push(newState);
                            vis[newState]=1;
                        }
                    }
                }
                q.pop();
            }
            moves++;
        }
        return -1;
    }
};
