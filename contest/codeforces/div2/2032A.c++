#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(2*n,0);
    int cnt=0;
    for(int i=0;i<2*n;i++) {
        cin>>a[i];
        if(a[i]) cnt++;
    }
    cout<<(cnt%2)<<" "<<min(2*n-cnt,cnt)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}