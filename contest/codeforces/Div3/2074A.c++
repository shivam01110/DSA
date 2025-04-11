#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,d,e;
    cin>>a>>b>>d>>e;
    if(a==b && b==d && e==d){
        cout<<"YES"<<endl;
    }
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