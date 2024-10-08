#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
void solve(){
    int n;cin>>n;
    ll maxheight=LLONG_MIN;
    vll h(n);
    bool desc=true;
    for(int i=0;i<n;i++){
        cin>>h[i];
        if(i>0 && h[i]>=h[i-1]) desc=false;
        maxheight=max(maxheight,h[i]);
    }
    if(desc) {cout<<maxheight<<endl; return;}
    ll time=maxheight;
    for(int j=n-1;j>=0;j--){
        time=max(time,h[j]+j);
    }
    cout<<time<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}