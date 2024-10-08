#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    int cnt=0;
    while(x>=0||y>=0){
        x-=min(x,k);
        cnt++;
        y-=min(y,k);
        cnt++;
    }
    cout<<cnt<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}