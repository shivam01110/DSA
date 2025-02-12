#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> m;
    int b,c;
    for(int i=0;i<k;i++){
        cin>>b>>c;
        m[b]+=c;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto p:m){
        pq.push(p.second);
        if(pq.size()>n) pq.pop();
    }
    int tot=0;
    while(!pq.empty()){
        tot+=pq.top();
        pq.pop();
    }
    return tot;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}