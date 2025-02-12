#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars){
    int n=chars.size(),p=0,l=0,r=0;
    while(r<n){
        while(r<n && chars[r]==chars[l]){
            r++;
        }
        string s=to_string(r-l);
        chars[p++]=chars[l];
        if(r-l>1){
            for(auto n:s){
                chars[p++]=n;
            }
        }
        l=r;
    }
    return p;
}