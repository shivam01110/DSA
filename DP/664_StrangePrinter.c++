#include <bits/stdc++.h>
using namespace std;

int solve(int l,int r,string s){
    if(l==r) return 1;
    if(l>r) return 0;
    int ans1=0,ans2=0;
    int j=l;
    while(j<=r && s[j]==s[l]){
        j++;
    }
    if(j==r+1) return 1;
    ans1=1+solve(j,r,s);
    for(;j<r;j++){
        
    }
}

int strangePrinter(string s) {
        
}
