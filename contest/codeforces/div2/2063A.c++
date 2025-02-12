#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int l,r;
    cin>>l>>r;
    if(l==r){
        if(l!=1) cout<<0<<endl;
        else cout<<1<<endl;
    }
    else{
        cout<<(r-l)<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}