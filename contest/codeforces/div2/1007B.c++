#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool perfect(ll sum){
    // ll sum=((n+1)*n)/2;
    ll rt=sqrt(sum);
    return (rt*rt==sum);
}

void solve(){
    ll n;
    cin>>n;
    ll sum=((n+1)*n)/2;
    ll rt=sqrt(sum);
    if(rt*rt==sum){
        cout<<-1<<endl;
        return;
    }
    sum=0;
    set<ll> arr;
    for(int i=1;i<=n;i++) arr.insert(i);
    while (!arr.empty()) {
        for (auto it = arr.rbegin(); it != arr.rend();) {
            ll a = *it;
            sum += a;
            if (perfect(sum)) {
                sum -= a;
                ++it;  
            } else {
                cout << a << " ";
                it = decltype(it)(arr.erase(next(it).base())); 
            }
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}