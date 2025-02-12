#include <bits/stdc++.h>
using namespace std;


int t,n;
void solve(){
    cin>>n;
    cout<<1<<" ";
    for(int i=1;i<=n-3;i++){
        cout<<i<<" ";
    }
    cout<<1<<" "<<2<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}