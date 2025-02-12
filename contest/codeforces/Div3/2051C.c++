#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t,n,m,k,sum,tot,a[300001],ki;

void solve(){
    sum=0;
    scanf("%lld%lld%lld",&n,&m,&k);
    tot=(n*(n+1))/2;
    for(ll i=1;i<=m;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=k;i++){
        scanf("%lld",&ki);
        sum+=ki;
    }
    for(ll i=1;i<=m;i++){
        if((k==n-1 && sum+a[i]==tot )||n==k) printf("1");
        else printf("0");
    }
    printf("\n");
}

int main(){
    scanf("%lld",&t);
    while(t--) solve();
    return 0;
}