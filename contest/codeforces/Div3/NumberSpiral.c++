#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int r,c;
    cin>>r>>c;
    ll res=0;
    if(r>=c){
        if(r%2) res=pow(r-1,2)+c;
        else res=pow(r,2)-(c-1);
    }
    else{
        if(c%2) res=pow(c,2)-(r-1);
        else res=pow(c-1,2)+r;
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