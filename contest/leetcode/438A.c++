#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int l=s.length();
        while(l>2){
            string str="";
            for(int i=0;i<l-1;i++){
                int sum=((s[i]-'0')+(s[i+1]-'0'))%10;
                str+=to_string(sum);
            }
            s=str;
            l=s.length();
        }
        return s[0]==s[1];
    }
};