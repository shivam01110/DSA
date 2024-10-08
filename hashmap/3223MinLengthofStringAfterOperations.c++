#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s) {
    vector<int> freq(26,0);
    int len=s.length();
    for(char c:s){
        freq[c-'a']++;
        if(freq[c-'a']==3){
            len-=2;
            freq[c-'a']-=2;
        }
    }
    return len;
}

int main(){
    string s;cin>>s;
    cout<<minimumLength(s)<<endl;
    return 0;
}