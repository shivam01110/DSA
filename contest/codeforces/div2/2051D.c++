#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    ll pair=0;
    ll lb=sum-y;
    ll rb=sum-x;
    for(int i=0;i<n;i++){
        ll left=lower_bound(a+i+1,a+n,lb-a[i])-a;
        ll right=upper_bound(a+i+1,a+n,rb-a[i])-a-1;
        if(lb-a[i]<=a[left] && a[right]<=rb-a[i]) pair+=right-left+1;
    }
    cout<<pair<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
