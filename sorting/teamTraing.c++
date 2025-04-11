#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;cin>>n;
    int x;cin>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int l=0,cnt=0;
    for(int r=0;r<n;r++){
        int len=r-l+1;
        if((len*a[r])>=x){
            cnt++;
            l=r+1;
        }
    }
    cout<<cnt<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}