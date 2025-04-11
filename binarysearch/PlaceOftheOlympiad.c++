#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool possible(ll n,ll m,ll k,ll l){
    ll grp=m/(l+1);
    ll seat=grp*l+(m%(l+1));
    return ((seat*n)>=k);
}

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll l=1,r=m;
    ll res=-1;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(possible(n,m,k,mid)){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}