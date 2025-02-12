#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(){
    int n;
    cin>>n;
    vector<ll> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1) return 1;
    vector<ll> diff(n,1);
    for(int i=n-2;i>=0;i=i-2){
        if(i<n-2) diff[i+1]=diff[i+2];
        diff[i]=max(diff[i+1],a[i+1]-a[i]);
    }
    if(n%2==0) return diff[0];
    ll left=a[1]-a[0],res=diff[1];
    for(int i=2;i<n;i=i+2){
        res=min(res,max(left,diff[i]));
        if(i<n-1) left=max(left,a[i+1]-a[i]);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}