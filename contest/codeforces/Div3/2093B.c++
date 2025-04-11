#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    string s;
    cin>>s;
    int l=s.length();
    int i=l-1;
    int cnt=0;
    while(i>=0 && s[i]=='0') {i--;cnt++;}
    for(int j=0;j<i;j++){
        if(s[j]!='0'){
            cnt++;
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