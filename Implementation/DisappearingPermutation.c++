#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(vector<int>& a,int& len,int i){
    if(a[i]==-i) return;
    len++;      //length of the chain
    int next=a[i];
    a[i]=-i;
    dfs(a,len,next);
}

void solve(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    int res=0;  //number of operation to make a valid permutation
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b;
    for(int i=0;i<n;i++){
        cin>>b;
        dfs(a,res,b);
        cout<<res<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}