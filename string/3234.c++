#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int res=0;
    for(int i=0;i<s.length();i++){
        int ones=0,zero=0;
        for(int j=i;j<s.length();j++){
            if(s[j]=='1')ones++;
            else zero++;
            if(ones>=pow(zero,2)) res++;
        }
    }   
    return res;
}