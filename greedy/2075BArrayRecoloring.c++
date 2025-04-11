#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll cost=0;
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k>1){
        sort(a.begin(), a.end(), greater<int>());
        cost= accumulate(a.begin(), a.begin() + k + 1, 0LL);
    }else{
        int l = *max_element(a.begin(), a.end() - 1);
        int r = *max_element(a.begin() + 1, a.end());
        cost = max(l + a.back(), r + a[0]);
    }
    cout<<cost<<endl;
}

int main(){
    cout<<"36.102371"<<" "<<"-115.174553"<<endl;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}