#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& freq1,vector<int>&freq2){
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int l1=s1.length(),l2=s2.length();
    if(l1>l2) return false;
    vector<int> freq1(26,0),freq2(26,0); 
    int l=0,r=0;  
    for(;r<l1;r++){
        freq1[s1[r]-'a']++;
        freq2[s2[r]-'a']++;
    }
    if(check(freq1,freq2)) return true;
    for(;r<l2;r++){
        freq2[s2[l]-'a']--;
        freq2[s2[r]-'a']++;
        if(check(freq1,freq2)) return true;
        l++;
    }
    return false;
}