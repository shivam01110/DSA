#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int x,y,a;
    cin>>x>>y>>a;
    int rem=(a%(x+y));
    if(rem<x){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}