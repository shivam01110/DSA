#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    int ai;
    for(int i=0;i<n;i++){
        cin>>ai;
        a[ai]++;
    }
    int odd=0;
    for(int i=0;i<n+1;i++){
        if(a[i]%2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


