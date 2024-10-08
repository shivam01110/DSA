// B. New Bakery
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
ll solEq(int a,int b,int k){
    ll sol=(k*(2*b-2*a+1-k))/2;
    return sol;
}
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll maxi=LLONG_MIN;
    ll ans=n*a;
    // if(b==a){
    //     cout<<ans<<endl;
    //     return;
    // }
    ll l=0,h=min(n,b);
    while(l<=h){
        ll mid=l+(h-l)/2;
        ll solMid=solEq(a,b,mid);
        ll solMidR=solEq(a,b,mid+1);    //solve for right side of Mid
        ll solMidL=solEq(a,b,mid-1);    //solve for left side of Mid
        maxi=max(maxi,solMid);
        if(solMidR>solMid){
            l=mid+1;
        }
        else if(solMidL>solMid){
            h=mid-1;
        }
        else break;
    }
    ans=+maxi;
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    while(t--) solve();
    return 0;
}