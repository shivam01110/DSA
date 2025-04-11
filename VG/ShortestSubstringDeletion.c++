// Problem statement: Find length of shortest substr that can be removed from a string resulting in a unique characters in the remaining string

// Approach: find the longest cyclic substring with unique chars that touches an end of the string, and then returns the length of the remainder as the substring to remove:
//time complexity: O(n)     n-->length of the string


#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    int len=s.length();
    int maxLen=0;   //maximum length of the cyclic substring with unique characters
    int currlen=0;  //current length of the cyclic substring with unique characters
    set<char> chars;
    for(int i=0;i<len;i++){
        while(chars.count(s[(i+currlen)%len])==0){
            chars.insert(s[(i+currlen)%len]);
            currlen+=1;
        }
        if(i==0 || (i+currlen)>=len){
            maxLen=max(maxLen,currlen);
        }
        chars.erase(s[i]);
        currlen-=1;
    }
    return len-maxLen;
}

int main(){
    string s;
    getline(cin,s);
    cout<<solve(s);
    return 0;
}

