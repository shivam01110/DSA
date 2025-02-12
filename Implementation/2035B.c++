#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    if(n==1||n==3) {cout<<-1<<endl;return;}
    if(n%2) {
        string start(n-4,'3');
        cout<<start+"6366";
    }
    else{
        string start(n-2,'3');
        cout<<start+"66";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}