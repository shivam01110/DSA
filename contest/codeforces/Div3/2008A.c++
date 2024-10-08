#include <bits/stdc++.h>
using namespace std;

void solve(){
    int o=0,t=0;
    cin>>o>>t;
    if(o%2 ||( o==0 && t%2)) cout<<"NO";
    else cout<<"YES";
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
