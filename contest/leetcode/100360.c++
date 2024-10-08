#include <bits/stdc++.h>
using namespace std;

int maxOperations(string s) {
    int ones=0,op=0,len=s.length();
    if(s[0]=='1') ones++;
    for(int i=1;i<len;i++){
        if(s[i]=='1' && s[i-1]=='0'){
            op+=ones;
        }
        if(s[i]=='1') ones++;
    }
    if(s[len-1]=='0') op+=ones;
    return op;
}

int main(){
    string s;
    cin>>s;
    cout<<maxOperations(s)<<endl;
    return 0;
}