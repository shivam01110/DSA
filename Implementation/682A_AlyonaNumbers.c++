#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int temp=n;
    n=min(m,temp);
    m=max(temp,m);
    vector<int> freq(6,0);
    for(int i=1;i<6;i++){
        int s=5-i;
        if(s==0) s=5;
        while(s<=m){
            s+=5;
            freq[i]+=1;
        }
    }
    freq[0]=freq[5];
    int res=0;
    for(int i=1;i<=n;i++){
        res+=freq[i%5];
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}