#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& vis,int ind,int n){
    if(ind>n) return 1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0 && (ind%i==0 || i%ind==0)){
            vis[i]=1;
            ans+=solve(vis,ind+1,n);
            vis[i]=0;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> visited(n+1,0);
    cout<<solve(visited,1,n);
    return 0;
}