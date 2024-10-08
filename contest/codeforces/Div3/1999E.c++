#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll logBase3(ll x) {
    return log(x) / log(3);
}


void solve(){
    int l,r;
    cin>>l>>r;
    ll ans=0;
    ans+=(logBase3(l)+1);
    ans+=ans;
    // int right=ans;
    // vector<ll> num;
    // for(int i=l+1;i<=r;i++){
    //     num.push_back(i);
    // }
    // int j=0;
    // for(int i=1;i<=ans;i++){
    //     num[j]=num[j]*3;
    //     j=(j+1)%num.size();
    // }
    for(int i=l+1;i<=r;i++){        
        ans+=(logBase3(i)+1);
    }
    cout<<ans<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


