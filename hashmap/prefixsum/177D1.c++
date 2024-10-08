#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> a(n,0);
    vector<int> b(m,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    vector<int> sum(m+1,0);
    for(int i=0;i<m;i++){
        sum[i+1]=sum[i]+b[i];
    }
    for(int i=0;i<n;i++){
        int r=min(m-1,i);   //right boundary of subarray in b that will affect a[i]
        int l=max(0,i-n+m); //left boundary of subarray in b that will affect a[i]
        a[i]=(a[i]+((sum[r+1]-sum[l])%c+c)%c)%c;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    solve();
    return 0;
}