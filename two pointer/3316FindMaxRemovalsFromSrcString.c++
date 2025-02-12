#include <bits/stdc++.h>
using namespace std;

int help(int i,int j,int t,string& src,string& pattern,vector<int>& target){
    if(i>=src.length()||t>=target.size()) return 0;
    if(j>=pattern.length()) return (target.size()-t);
    int res=INT_MIN;
    if(src[i]==src[j]){
        if(i==target[t]){
            res=max(res,1+help(i+1,j,t+1,src,pattern,target));//not consider
            res=max(res,help(i+1,j+1,t+1,src,pattern,target));
        }
        else{
            res=max(res,help(i+1,j+1,t,src,pattern,target));            
        }
    }
    else{
        if(i==target[t]){
            res=max(res,1+help(i+1,j,t+1,src,pattern,target));//not consider
        }
    }
    return res;
}

int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
    int p1=0,p2=0,cnt=0;
    for(int i=0;i<source.length();i++){
        if(source[i]==pattern[p1]){
            p1++;
            if(i==targetIndices[p2]){
                p2++;
            }
        }
        else{
            if(i==targetIndices[p2]){
                cnt++;
                p2++;
            }
        }
        if(p1>=pattern.length()){
            cnt+=(targetIndices.size()-p2);
            break;
        }
    }
    return cnt;
}