#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll t,n,a[200001],b[200001],diff[200001];
void solve(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    for(ll i=1;i<=n;i++){
        diff[i]=a[i]-b[i];
    }
    ll cntneg=0,mini=INT_MAX,negdiff=0;
    for(ll i=1;i<=n;i++){
        if(diff[i]<0) {negdiff=abs(diff[i]);cntneg++;}
        if(cntneg==2) {printf("%s","NO\n");return;}
        if(diff[i]>=0) mini=min(mini,diff[i]);
    }
    if(negdiff<=mini)printf("%s","YES\n");
    else printf("%s","NO\n");
}

int main(){
    scanf("%lld",&t);
    while(t--){
        solve();
    }
    return 0;
}