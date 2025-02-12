#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0,cnt=0;
    while(l<n && s[l]!='p') {
        if(s[l]=='s') cnt++;
        l++;
    }
    while(l<n){
        if((s[l]=='.' && cnt) || (s[l]=='s')) {cout<<"NO"<<endl;return;}
        l++;
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}