//Robin hood

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(){
    int n;
    cin>>n;
    vector<ll> a(n,0);
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    if(n<=2) return -1;
    sort(a.begin(),a.end());
    ll mid=a[n/2];
    ll x=mid*2*n-sum;
    return max(x+1,0ll);
}

int main(){
    int t;cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}