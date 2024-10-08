//354C. Vasya and Robot
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void solve(){
    int n,l,r,Ql,Qr;
    cin>>n>>l>>r>>Ql>>Qr;
    vi w(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>w[i];
        w[i]+=w[i-1];
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<=n;i++){
        ll curr=w[i]*l+(w[n]-w[i])*r;
        if(i<n-i) curr+=(n-1-2*i)*Qr;
        if(i>n-i) curr+=(2*i-n-1)*Ql;
        ans=min(ans,curr);
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}