#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    if((a%2 && b==2*a) ||(a==2*b && b%2) || (a%2 && b%2)) cout<<"NO";
    else cout<<"YES";
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}