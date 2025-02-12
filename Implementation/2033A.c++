#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int step=1,x=0,turn=0;
    while(abs(x)<=n){
        if(turn) x+=step;
        else x-=step;
        step+=2;
        turn=!turn;
    }
    (turn)?cout<<"Sakurako":cout<<"Kosuke";
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}