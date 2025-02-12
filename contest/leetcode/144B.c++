#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long backward(char s,char t,vector<int>& prevCost){
        int a=s-'a',b=t-'a';
        long long tot=0;
        while(a!=b){
            tot+=prevCost[a];
            a=(a-1+26)%26;
        }
        return tot;
    }
    long long forward(char s,char t,vector<int>& nextCost){
        int a=s-'a',b=t-'a';
        long long tot=0;
        while(a!=b){
            tot+=nextCost[a];
            a=(a+1)%26;
        }
        return tot;
    }
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long tot=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            tot+=min(forward(s[i],t[i],nextCost),backward(s[i],t[i],previousCost));
        }
        return tot;
    }
};

int main(){
    cout<<('a'-'a')<<endl;
}