#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(){
    ll n,m,r,c;
    cin>>n>>m>>r>>c;
    ll tot=(n-r)*(2*m-1)+m-c;
    return tot;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}