#include <bits/stdc++.h>
using namespace std;

string match(vector<int> &a,string s){
    if(a.size()!=s.length()) return "NO";
    unordered_map<int,char> m1;    //n-->s
    unordered_map<char,int> m2;    //s-->n
    for(int i=0;i<s.length();i++){
        if((m1.find(a[i])!=m1.end() && m1[a[i]]!=s[i] )|| (m2.find(s[i])!=m2.end() && m2[s[i]]!=a[i] )) return "NO";
        m1[a[i]]=s[i];
        m2[s[i]]=a[i];
    }
    return "YES";
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;cin>>m;
    vector<string> s(m);
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        cout<<match(a,s[i])<<endl;
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