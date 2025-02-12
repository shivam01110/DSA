#include <bits/stdc++.h>
using namespace std;

#define ll long long

int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
void solve(){
    int n,d;
    cin>>n>>d;
    cout<<1;
    if(n>=3 || d%3==0) cout<<" "<<3;
    if(d==5) cout<<" "<<5;
    if(n>=3 || d==7) cout<<" "<<7;
    if(n>=6 || ((fact(n)*d%9)==0)) cout<<" "<<9;
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}