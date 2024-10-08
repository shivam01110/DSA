//355A. Vasya and Digital Root
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void solve(){
    int k,d;
    cin>>k>>d;
    if(k>1 && d==0) {cout<<"No solution"<<endl; return;}
    string ans=to_string(d)+string(k-1,'0');
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}