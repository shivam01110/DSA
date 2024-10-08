#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    int maxi=INT_MIN;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        m[arr[i]]++;
        maxi=max(maxi,m[arr[i]]);
    }
    cout<<n-maxi<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}