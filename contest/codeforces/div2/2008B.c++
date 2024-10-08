#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sq=sqrt(n);
    if(sq*sq==n){
        int cnt=0;
        for(auto c:s){
            if(c=='0') cnt++;
        }
        if(cnt==(sq-2)*(sq-2)|| n==1 && cnt==0){cout<<"YES"<<endl;return;}
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
