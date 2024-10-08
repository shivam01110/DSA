#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;
    string t;cin>>t;
    int l1=s.length();
    int l2=t.length();
    int j=0;
    for(int i=0;i<l1;i++){
        if(j<l2 && s[i]==t[j]){
            j++;
        }
        else if(j<l2 && s[i]=='?'){
            s[i]=t[j];
            j++;
        }
        else if(j>=l2 && s[i]=='?'){
            s[i]='v';
        }
    }
    if(j>=l2){
        cout<<"YES"<<endl;
        cout<<s<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}