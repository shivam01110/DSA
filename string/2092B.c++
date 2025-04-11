#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(i%2==0 && b[i]=='0') c1++;
        if(i%2 && a[i]=='0') c1++;
    }
    int reqzero=n/2;
    if(reqzero>c1){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(i%2 && b[i]=='0') c2++;
        if(i%2==0 && a[i]=='0') c2++;
    }
    int req0=(n+1)/2;
    if(req0>c2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}