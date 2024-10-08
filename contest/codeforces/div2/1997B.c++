#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;cin>>n;
    string r1,r2;
    cin>>r1>>r2;
    int res=0;
    for(int i=1;i<n-1;i++){
        if(r1[i]=='.' && r1[i-1]=='.' && r1[i+1]=='.' && r2[i-1]=='x' && r2[i+1]=='x' && r2[i]=='.') res++;
        if(r2[i]=='.' && r2[i-1]=='.' && r2[i+1]=='.' && r1[i-1]=='x' && r1[i+1]=='x' && r1[i]=='.') res++;
    }
    cout<<res<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}