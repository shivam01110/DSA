#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    int i=0,j=s.length()-1;
    while(i<j && s[i]==s[j]){
        i++;
        j--;
    }
    return (i>=j);
}

string sub1(string& s){
    if(s=="1") return "0";
    int j=s.length()-1;
    while(j>=0 && s[j]=='0'){
        s[j]='9';
        j--;
    }
    if(j>=0) s[j]=s[j]-1;
    int i=0;
    while(i<s.length() && s[i]=='0'){
        i++;
    }
    return s.substr(i,s.length()-i);
}


string add1(string& s){
    int j=s.length()-1;
    while(j>=0 && s[j]=='9'){
        s[j]='0';
        j--;
    }
    if(j>=0) s[j]=s[j]+1;
    else s='1'+s;
    return s;
}

string nearestPalindromic(string n) {
    string prev=n;
    string next=n;
    while(1){
        prev=sub1(prev);
        next=add1(next);
        if(palindrome(prev)) return prev;
        if(palindrome(next)) return next;
    }
    return "MARTHA";
}

int main(){
    string num="1111";
    // num[0]=num[0]-1;
    // cout<<sub1(num)<<endl;
    // cout<<add1(num)<<endl;
    cout<<nearestPalindromic(num)<<endl;
    return 0;
}