#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        int len=s.length();
        vector<vector<int>> pos(26);
        long long res=0;
        for(int i=0;i<len;i++){
            int pres=s[i]-'a';
            int req=25-pres;
            if(!pos[req].empty()){
                res+=i-pos[req].back();
                pos[req].pop_back();
            }
            else{
                pos[s[i]-'a'].push_back(i);
            }
        }
        return res;
    }
};