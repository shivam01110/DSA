#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string& s){
    int len=s.length();
    vector<pair<int,int>> freq(26,make_pair(0,len)); //{freq,pos}
    for(int i=0;i<len;i++){
        freq[s[i]-'a'].first++;
        freq[s[i]-'a'].second=min(freq[s[i]-'a'].second,i);
    }
    sort(freq.begin(),freq.end(),[](const pair<int,int>& a,const pair<int,int>& b){
        if(a.first!=b.first) return a.first>b.first;
        return a.second<b.second;
    });
    string res="";
    for(auto p:freq){
        string part(p.first,s[p.second]);
        res+=part;
    }
    cout<<res<<endl;
}

int main(){
    string s;cin>>s;
    solve(s);
    return 0;
}