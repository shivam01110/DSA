//1856A. Tales of a Sort
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define vll vector<ll>
void solve(){
    int n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(max(0LL,a[i]-ans)>max(0LL,a[i+1]-ans)){
            ans+=max(0LL,a[i]-ans);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}