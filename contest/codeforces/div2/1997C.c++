#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;cin>>n;
    string rbs;
    cin>>rbs;
    int res=0;
    stack<int> pos;
    for(int i=0;i<n;i++){
        if(!pos.empty() && rbs[i]!='('){
            res+=i-pos.top();
            pos.pop();
        }
        else pos.push(i);
    }
    cout<<res<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}