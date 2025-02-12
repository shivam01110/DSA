#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        vector<int> freq(10,0);
        int n=s.length();
        for(int i=0;i<s.length();i++){
            freq[s[i]-'0']++;
        }
        for(int i=0;i<n-1;i++){
            if(freq[s[i]-'0']==s[i]-'0' && freq[s[i+1]-'0']==(s[i+1]-'0')){
                return s.substr(i,2);
            }
        }
        return "";
    }
};