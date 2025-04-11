#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> p;

void countPrimes(ll n) {
    if(n<=2) return ;
    vector<bool> prime(n+1,1);
    prime[0]=0;prime[1]=0;
    for(ll i=2;i<=sqrt(n);i++){
        if(prime[i]){
            for(ll j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) p.push_back(i);
    }
}

void solve(){
    int n;
    cin>>n;
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<664579 && i*p[j]<=n;j++){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main(){
    countPrimes(10000001);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}