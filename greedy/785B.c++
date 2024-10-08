#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define fl(i,n,inc) for(int i=0;i<n;i+=inc)
void sol(){
    int n,i=0;ll ans=0;
    cin>>n;
    vp a(n);
    fl(i,n,1){
        ll l,r;
        cin>>l>>r;
        a[i]={l,r};
    }
    int m;
    cin>>m;
    vp b(m);
    fl(i,m,1){
        ll l,r;
        cin>>l>>r;
        b[i]={l,r};
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    fl(i,n,1){
        if(a[i].first <b.back().first && a[i].second<b.back().first){
            ans=max(ans,b.back().first-a[i].second);
        }
        if(a[i].first >b.back().second && a[i].second>b.back().second){
            ans=max(ans,abs(b.back().second-a[i].first));
        }
    }
    fl(i,m,1){
        if(b[i].first <a.back().first && b[i].second<a.back().first){
            ans=max(ans,a.back().first-b[i].second);
        }
        if(b[i].first >a.back().second && b[i].second>a.back().second){
            ans=max(ans,abs(a.back().second-b[i].first));
        }
    }
    cout<<ans<<endl;
}
int main(){
    // int t;cin>>t;
    // while(t--)
    sol();
    return 0;
}