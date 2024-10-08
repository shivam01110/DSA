#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n,0),b(n,0);
    int match1=1,match2=2;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(a[i]!=b[i]){
            match1=0;
        }
        if(b[i]!=a[n-1-i]){
            match2=0;
        }
    }
    if(match1||match2){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alice"<<endl;
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