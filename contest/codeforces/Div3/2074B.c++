#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve(){
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        sum+=a;
    }
    sum=sum-(n-1);
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}