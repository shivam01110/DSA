#include <bits/stdc++.h>
using namespace std;

bool check(unordered_map<char,int>& m1,unordered_map<char,int>& m2){
    for(auto p:m2){
        if(m1[p.first]<p.second) return false;
    }
    return true;
}

string minWindow(string s, string t) {
    int m=s.length(),n=t.length();
    if(m<n) return"";
    int l=0,r=0,p1=0,len=INT_MAX;
    unordered_map<char,int> m1,m2;
    for(;r<m;r++){
        m1[s[r]]++;
        if(r<n)m2[t[r]]++;
        while(r>=n-1 && check(m1,m2)){
            if(r-l+1<len){
                p1=l;
                len=r-l+1;
            }
            m1[s[l]]--;
            l++;
        }
    }
    if(len==INT_MAX) return "";
    return s.substr(p1,len);
}