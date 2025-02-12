#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    if(k==1 && n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    if(k%2==0){
        cout<<3<<endl;
        cout<<1<<" "<<k<<" "<<k+1<<endl;
    }
    else{
        if(k-2<1 || k+2>n){
            cout<<-1<<endl;
        }
        else{
            cout<<3<<endl;
            cout<<1<<" "<<k-1<<" "<<k+2<<endl;
        }
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