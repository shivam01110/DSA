#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    if(n<k || k==1){
        cout<<n<<endl;
        return;
    }
    int operation=0;
    while(n>=k){
        ll temp=k;
        while(n>=temp){
            temp=temp*k;
        }
        temp/=k;
        n-=temp;
        operation++;
    }
    operation+=n;
    cout<<operation<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

