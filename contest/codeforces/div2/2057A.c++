#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    ll res=max(n,m)+1;
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}