#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars){
    int n=chars.size(),l=0,r=0,res=0;
    while(r<n){
        res++;
        l=r;
        while(r<n && chars[l]==chars[r]){
            r++;
        }
        if(r-l>1) res+=to_string(r-l).length();
    }
    return res;
}