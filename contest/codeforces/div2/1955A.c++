#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    if(k==0){
        cout<<k<<endl;
        return;
    }
    int mid=(2+n+n)/2;
    int diagonal=1;
    k-=mid-1;mid--;
    while (k>0){
        k-=mid-1;
        diagonal++;
        if(k>0){
            k-=mid-1;
            diagonal++;
        }
        mid--;
    }
    cout<<diagonal<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}