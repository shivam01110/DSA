#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll p=1;
    while(n/4>=1){
        n=n/4;
        p=p*2;
    }
    cout<<p<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}