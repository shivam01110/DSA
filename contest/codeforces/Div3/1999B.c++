#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans=0;
        if(a>c && b>d) ans+=2;
        if(a>d && b>c) ans+=2;
        if(a==c && b>d) ans+=2;
        if(a==d && b>c) ans+=2;
        if(b==c && a>d) ans+=2;
        if(b==d && a>c) ans+=2;
        cout<<ans<<endl;
    }
    return 0;
}