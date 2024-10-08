#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<int> x(n+1,0);
    vector<int> y(n+1,0);
    ll px=0,py=0,cnt=0;
    for(int i=0;i<n;i++){
        int cx,cy;
        cin>>cx>>cy;
        if(cy==0) {x[cx]=1;px++;}
        else {y[cx]=1;py++;}
    }
    for(int i=0;i<n+1;i++){
        if(x[i] && y[i]){
            cnt+=px-1;
            cnt+=py-1;
        }
        if(i>0 && i<n && x[i] && y[i-1] && y[i+1]) cnt++;
        if(i>0 && i<n && y[i] && x[i-1] && x[i+1]) cnt++;
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