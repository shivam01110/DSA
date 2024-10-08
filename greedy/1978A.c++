// A. Alice and Books
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=a[n-1];
    ans+=*max_element(a.begin(),a.end()-1);
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}