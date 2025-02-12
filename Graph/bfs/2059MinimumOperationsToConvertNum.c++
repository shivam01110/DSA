#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> vis(1001,0);
        int moves=0;
        queue<int> q;
        vis[start]=1;
        q.push(start);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int x=q.front();
                q.pop();
                //try all possible operation
                for(auto n:nums){
                    if(x+n==goal ||(x^n)==goal|| x-n==goal) return moves+1;
                    //1st operation
                    if(0<=(x+n) && (x+n)<=1000 && vis[x+n]!=1){
                        vis[x+n]=1;
                        q.push(x+n);
                    }
                    //2nd operation
                    if(0<=(x-n) && (x-n)<=1000 && vis[x-n]!=1){
                        vis[x-n]=1;
                        q.push(x-n);
                    }
                    //3rd operation
                    if(0<=(x^n) && (x^n)<=1000 && vis[x^n]!=1){
                        vis[x^n]=1;
                        q.push(x^n);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};