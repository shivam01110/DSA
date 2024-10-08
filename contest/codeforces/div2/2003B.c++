#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int mid=n/2;
    cout<<a[mid]<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}