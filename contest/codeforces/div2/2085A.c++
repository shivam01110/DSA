#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,k;
    cin>>n;
    cin>>k;
    string s;
    cin>>s;
    int l=0,r=n-1;
    while(k>=0){
        if(s[l]>s[r]){
            swap(s[l],s[r]);
            k--;
            break;
        }
        l++;r--;
    }
    for(int i=0;i<=n/2;i++){
        if(s[i]>s[n-i-1]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}