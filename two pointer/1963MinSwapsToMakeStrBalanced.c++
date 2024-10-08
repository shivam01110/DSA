//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int l=0,r=s.length()-1,cnt=0,close=0,open=0;
        for(;l<r;l++){
            if(s[l]==']') close++;
            else open++;
            if(close>open){
                while(r>l && s[r--]==']');
                swap(s[l],s[r]);
                cnt++;
                close--;
                open++;
            }
        }
        return cnt;
    }
};