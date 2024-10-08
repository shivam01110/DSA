#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll add=a[n-2];
    for(int i=n-3;i>-1;i--) add-=a[i];
    a[n-1]-=add;
    cout<<a[n-1]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}