#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    int len=s.length(),res=0,close=0,open=0;
    for(int i=0;i<len;i++){
        if(s[i]=='(') open++;
        else close++;
        if(close>open) {open++;res++;}
    }
    if(open>close) res+=open-close;
    return res;
}