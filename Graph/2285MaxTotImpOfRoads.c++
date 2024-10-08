#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int r=roads.size();
        vector<int> out(n,0);// outgoing edges
        for(int i=0;i<r;i++){
            out[roads[i][0]]++;
            out[roads[i][1]]++;
        }
        for(int i=0;i<n;i++){
            cout<<out[i]<<" ";
        }
        cout<<endl;
        priority_queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({out[i],i});
        }
        int imp=n;
        while (!q.empty()){
            out[q.top().second]=imp;    //Assign the maximum importance to the city which have maximum outgoing/incoming road
            imp--;
            q.pop();
        }
        ll totImp=0;
        for(int i=0;i<r;i++){
            totImp=totImp+out[roads[i][0]]+out[roads[i][1]];
        }
        return totImp;
    }
};
int main(){
    Solution sol;
    int n=5;
    vector<vector<int>> roads={{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    cout<<sol.maximumImportance(n,roads)<<endl;
    return 0;
}