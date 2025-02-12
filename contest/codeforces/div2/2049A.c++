#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,r=n-1;
    while(l<n && arr[l]==0) l++;
    if(l==n) {cout<<0<<endl;return;}
    while(l<r && arr[r]==0) r--;
    int mini=INT_MAX;
    for(int i=l;i<=r;i++){
        mini=min(arr[i],mini);
    }
    if(mini) cout<<1<<endl;
    else cout<<2<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}