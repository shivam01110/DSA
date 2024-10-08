//1932B. Chaya Calendar 
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void solve(){
    int n;
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(ans<a){
            ans=a;
        }
        else{
            int q=ans/a;
            ans=(q+1)*a;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}