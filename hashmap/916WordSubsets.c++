#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void updatefreq(string &w,vector<int>& freq){
        vector<int> f(26,0);
        for(int i=0;i<w.length();i++){
            f[w[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            freq[i]=max(freq[i],f[i]);
        }
    }
    bool isUniversal(vector<int>& freq,string w){
        vector<int> f(26,0);
        for(int i=0;i<w.length();i++){
            f[w[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>f[i]) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq2(26,0);
        vector<string> res;
        for(auto w:words2){
            updatefreq(w,freq2);
        }
        for(auto w:words1){
            if(isUniversal(freq2,w)) res.push_back(w);
        }
        return res;
    }
};
