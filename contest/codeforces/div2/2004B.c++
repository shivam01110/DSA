#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int l=101,r=-1;
    for(int i=min(a,c);i<=max(b,d);i++){
        if(i>=a && i<=b && i>=c && i<=d){
            l=min(l,i);
            r=max(r,i);
        }
    }
    int mini=min(a,c);
    int maxi=max(b,d);
    if(l<=r){
        int gates=r-l;
        if(maxi>r) gates++;
        if(mini<l) gates++;
        cout<<gates<<endl;
    }
    else{
        cout<<1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}