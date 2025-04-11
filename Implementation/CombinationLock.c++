#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    if(n%2==0) {cout<<-1<<endl; return;}
    for(int i=n;i>0;i--){
        cout<<i<<" ";
    }
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