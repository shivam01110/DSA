#include <bits/stdc++.h>
using namespace std;

bool doesAliceWin(string s) {
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            return true;
        }
    }
    return false;
}