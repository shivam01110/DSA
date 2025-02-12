#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        map<int,int> m;
        for(auto it:shifts){
            m[it[0]]+=(it[2]==0)?-1:1;
            m[it[1]+1]-=(it[2]==0)?-1:1;
        }
        int shift=0;
        auto it=m.begin();
        shift+=it->second;
        int start=it->first;
        it++;
        for(;it!=m.end();it++){
            int end=it->first;
            for(int i=start;i<end;i++){
                s[i]='a'+(s[i]-'a'+shift+26)%26;
            }
            start=end;
            shift+=it->second;
        }
        return s;
    }
};