#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char,int> m;
    for(int i=0;i<s.length();i++){
        m[s[i]]=i;
    }
    string res="";
    vector<int> taken(26,0);
    for(int i=0;i<s.length();i++){
        if(taken[s[i]-'a']) continue;
        if(res.empty() || (res.back()<s[i] && taken[s[i]-'a']==0)){
            taken[s[i]-'a']=1;
            res+=s[i];
        }
        else {
            while(!res.empty() && res.back()>s[i] && m[res.back()]>i){
                taken[res.back()-'a']=0;
                res.pop_back();
            }
            res.push_back(s[i]);
            taken[s[i]-'a']=1;
        }
    }
    return res;
}

int main(){
    string s="cbacdcbc";
    // string s="bcabc";
    cout<<removeDuplicateLetters(s)<<endl;
    return 0;
}