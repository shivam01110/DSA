#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> p(n);
    int e=n-1,lastInd=n-1;
    for(;e>-1;e-=2){
        p[e]=a[lastInd--];
    }
    e=n-2;
    for(;e>-1;e-=2) p[e]=a[lastInd--];
    for(int i=0;i<n;i++){
        if (!((p[(i + n) % n] > p[(i + 1 + n) % n] && p[(i + n) % n] > p[(i - 1 + n) % n]) || 
              (p[(i + n) % n] < p[(i + 1 + n) % n] && p[(i + n) % n] < p[(i - 1 + n) % n]))) {
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}