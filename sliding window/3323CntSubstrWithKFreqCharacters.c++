#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(vector<int>& freq,int k){
        for(int f:freq){
            if(f>=k) return true;
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        int i=0,len=s.length();
        vector<int> freq(26,0);
        int l=0,res=0;
        for(int r=0;r<len;r++){
            freq[s[r]-'a']++;
            while(l<=r && valid(freq,k)){
                freq[s[l]-'a']--;
                l++;
                res+=(len-r);
            }
        }
        return res;
    }
};