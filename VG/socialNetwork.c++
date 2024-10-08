#include <bits/stdc++.h>
using namespace std;

void socailGrpahs(vector<int> counts){
    int n=counts.size();
    vector<queue<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[counts[i]].push(i);
    }
    vector<int> visted(n+1,0);
    for(int i=0;i<n;i++){
        if(visted[i]==0){
            int group=counts[i];
            int g=group;
            while(g){
                visted[adj[group].front()]=1;
                cout<<adj[group].front()<<" ";
                adj[group].pop();
                g--;
            }
            cout<<endl;
        }
    }
}

int main(){
    int n;cin>>n;
    vector<int> counts(n);
    for(int i=0;i<n;i++){
        cin>>counts[i];
    }
    socailGrpahs(counts);
    return 0;
}