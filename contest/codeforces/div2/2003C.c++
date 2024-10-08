#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,int> m;
    for(char c:s){
        m[c]++;
    }
    queue<pair<char,int>> q;
    for(auto it:m){
        q.push({it.first,it.second});
    }
    string res="";
    while(!q.empty()){
        res+=q.front().first;
        if(q.front().second!=1){
            q.push({q.front().first,q.front().second-1});
        }
        q.pop();
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