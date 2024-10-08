#include <bits/stdc++.h>
using namespace std;

// void solve(){
//     int n;cin>>n;
//     vector<int> b(n-1);
//     for(int i=0;i<n-1;i++) {
//         cin>>b[i];
//         if(i) cout<<min(b[i],b[i-1]);
//         else cout<<b[0];
//         cout<<" ";
//     }
//     cout<<b[n-2]<<'\n';
// }

void solve(){
    int n,prev=INT_MAX,curr=-1;cin>>n;
    for(int i=0;i<n-1;i++) {
        cin>>curr;
        cout<<min(curr,prev)<<" ";
        prev=curr;
    }
    cout<<curr<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}