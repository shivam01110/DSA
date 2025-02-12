#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0;
        for(char i:s){
            if(i=='a') a++;
            if(i=='b') b++;
            if(i=='c') c++;
        }
        a=a-k,b=b-k,c=c-k;
        if(a<0 ||b<0 || c<0) return -1;
        int l=0, r=0, n=s.size(), maxi=0;
        int cnt_a=0, cnt_b=0, cnt_c=0;
        while (r<n){
            char ch=s[r];
            if(ch=='a') cnt_a++;
            if(ch=='b') cnt_b++;
            if(ch=='c') cnt_c++;
            while(cnt_a>a || cnt_b>b || cnt_c>c){
                if(s[l]=='a') cnt_a--;
                if(s[l]=='b') cnt_b--;
                if(s[l]=='c') cnt_c--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return n-maxi;       
    }
};