#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n>2) cout<<"NO";
    else if(n==2) {
        if(abs(a[0]-a[1])>1) cout<<"YES";
        else cout<<"NO";
    } 
    else cout<<"YES";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
