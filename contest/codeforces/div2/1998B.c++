#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int p;
    for(int i=1;i<=n;i++){
        cin>>p;
        (p==1)?cout<<n:cout<<p-1;
        cout<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}