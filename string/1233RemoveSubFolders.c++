#include <bits/stdc++.h>
using namespace std;

bool subfolder(string f,string sf){
    if(sf.length()<=f.length()) return false;
    int i=0;
    for(;i<f.length();i++){
        if(f[i]!=sf[i]) return false;
    }
    if(sf[i]=='/') return true;
    return false;
}

vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(),folder.end());
    vector<string> res;
    int i=0,len=folder.size();
    while(i<len){
        int j=i+1;
        while(j<len && subfolder(folder[i],folder[j])) j++;
        res.push_back(folder[i]);
        i=j;
    } 
    return res;
}