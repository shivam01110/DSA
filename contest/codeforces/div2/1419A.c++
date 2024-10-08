#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string num;cin>>num;
    bool raze=false,breach=false;
    for(int i=0;i<n;i++){
        if(i%2==0 && (num[i]-'0')%2) raze=1;
        if(i%2 && (num[i]-'0')%2==0) breach=1;
    }
    if(n%2){
        if(raze) cout<<1<<endl;
        else cout<<2<<endl;
    }
    else{
        if(breach) cout<<2<<endl;
        else cout<<1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}