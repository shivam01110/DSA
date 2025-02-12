#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    unordered_map<string,int> freq(string s,int l,int len){
        unordered_map<string,int> f;
        string sub="";
        for(int i=0;i<len;i+=l){
            sub=s.substr(i,l);
            f[sub]=f[sub]+1;
        }
        return f;
    }
    bool containAinB(unordered_map<string,int>& a,unordered_map<string,int>& b){
        auto it=a.begin();
        while(it!=a.end()){
            if(b[it->first]!=it->second) return false;
            it++;
        }
        return true;
    }
    bool isPossibleToRearrange(string s, string t, int k) {
        int len=s.length(),l=len/k;
        unordered_map<string,int> f1=freq(s,l,len);
        unordered_map<string,int> f2=freq(t,l,len);
        return containAinB(f1,f2) && containAinB(f2,f1);
    }
};