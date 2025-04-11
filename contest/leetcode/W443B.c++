#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(string s){
        int i=0,j=s.length()-1;
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        return (i>=j);
    }
    int longestPalindrome(string s, string t) {
        vector<string> subs;
        vector<string> subt;
        int lens=s.length();
        int lent=t.length();
        int res=0;
        for(int i=0;i<lens;i++){
            string sub="";
            for(int j=i;j<lens;j++){
                sub+=s[j];
                subs.push_back(sub);
                if(palindrome(sub)) res=max(res,j-i+1);
            }
        }
        for(int i=0;i<lent;i++){
            string sub="";
            for(int j=i;j<lent;j++){
                sub+=t[j];
                subt.push_back(sub);
                if(palindrome(sub)) res=max(res,j-i+1);
            }
        }
        int l1=subs.size(),l2=subt.size();
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                string concat=subs[i];
                concat+=subt[j];
                if(palindrome(concat)) res=max(res,(int)concat.length());
            }
        }
        return res;
    }
};