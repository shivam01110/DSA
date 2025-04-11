#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,x;
    cin>>n>>x;
    int sum=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        sum+=a;
    }
    if(sum%n==0 && sum/n==x){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}