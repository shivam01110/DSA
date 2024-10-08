#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,s,m;
    cin>>n>>s>>m;
    int ans=0;
    int prev=0;
    while(n--){
        int l,r;
        cin>>l>>r;
        if(l-prev>=s){
            ans=1;
        }
        prev=r;
    }
    if(m-prev>=s) ans=1;
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}