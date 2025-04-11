#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> v(n);
    ll tot=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        tot+=v[i];
    }
    ll res=n*k;
    ll unit=x/tot;
    res=res-unit*n;
    ll currremove=unit*tot;
    if(tot*k>=x && x%tot==0) res++;
    for(int i=n-1;i>=0 && currremove+v[i]<x ;i--){
        currremove+=v[i];
        res--;
    }
    cout<<max(0ll,res)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}