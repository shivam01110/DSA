#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=1000001;
vector<int> prime(N,1);
void Primes() {
    prime[0]=0;prime[1]=0;
    for(int i=2;i<=sqrt(N);i++){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i){
                prime[j]=0;
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    ll x;
    for(int i=0;i<n;i++){
        cin>>x;
        ll y=sqrt(x);
        if(prime[y] && y*y==x){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
}

int main(){
    Primes();
    solve();
    return 0;
}