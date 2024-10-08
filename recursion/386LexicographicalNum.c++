#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& ans,int n,int curr){
    if(curr>n) return;
    ans.push_back(curr);
    for(int i=0;i<10;i++){
        curr=curr*10+i;
        solve(ans,n,curr);
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> ans;
    solve(ans,n,1);
    return ans;
}