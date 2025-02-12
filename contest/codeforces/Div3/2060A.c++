#include <bits/stdc++.h>
using namespace std;

int fibo(int a,int b,int c,int d,int e){
    int term=0;
    if(c==a+b) term++;
    if(d==b+c) term++;
    if(e==c+d) term++;
    return term;
}

void solve(){
    int a,b,d,e;
    cin>>a>>b>>d>>e;
    int c1=a+b,c2=d-b;
    int res1=fibo(a,b,c1,d,e);
    int res2=fibo(a,b,c2,d,e);
    cout<<max(res1,res2)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}