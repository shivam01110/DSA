#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> f={1};
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            f.back()++;
        }
        else{
            f.push_back(1);
        }
    }
    int res=f.size();
    sort(f.begin(),f.end());
    for(int i=0;i<f.size()-1 && f[i]<=k;i++){
        res=max(1,res-1);
        k=k-f[i];
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}