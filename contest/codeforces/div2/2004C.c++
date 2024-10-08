#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int A=0,B=0;
    for(int i=n-2;i>=0;i-=2){
        A+=a[i+1];
        int diff=a[i+1]-a[i];
        a[i]=a[i]+min(diff,k);
        B+=a[i];
        k-=min(k,diff);
    }
    if(n%2) A+=a[0];
    cout<<A-B<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}