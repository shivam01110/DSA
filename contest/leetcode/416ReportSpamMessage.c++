#include <bits/stdc++.h>
using namespace std;

bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
    sort(bannedWords.begin(),bannedWords.end());
    int cnt=0;
    for(string m:message){
        auto it=binary_search(bannedWords.begin(),bannedWords.end(),m);
        if(it) cnt++;
        if(cnt>=2) return true;
    }  
    return false;
}