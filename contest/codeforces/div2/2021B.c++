#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,x;
    cin>> n>>x;
    int ele;
    unordered_map<ll,ll> m;
    for (int i=0; i<n;i++){
        cin>>ele;
        m[ele]++;
    }
    ll mex=0;
    while(mex<n && m[mex]){
        if(m[mex]>1){
            m[mex+x]+=m[mex]-1;
        }
        mex++;
    }
    cout<<mex<<endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}