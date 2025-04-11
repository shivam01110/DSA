#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPrime(ll n) {
    if (n <= 1) return false; // 0 and 1 are not prime
    if (n == 2 || n == 3) return true; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void solve(){
    ll x,k;
    cin>>x>>k;
    if((isPrime(x) && k==1 )||(x==1 && k==2)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    // cout<<isPrime(1111111);
    return 0;
}