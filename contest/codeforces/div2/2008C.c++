#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l,r;
    cin>>l>>r;
    int cnt=1;
    int diff=1;
    while(l<r){
        l+=diff;
        diff++;
        if(l<=r)cnt++;
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
