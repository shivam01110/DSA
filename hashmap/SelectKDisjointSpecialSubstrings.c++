#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int l=0;
    int front[26],back[26];
    int dp[50001];
    vector<vector<int>> freq;

    int possible(int s,int e){
        int right=e;
        bool updateRight=true;
        while(updateRight){
            updateRight=false;
            for(int i=0;i<26;i++){
                if(front[i]!=-1 && front[i]<s && (freq[i][right+1]-freq[i][s])>0) return -1;
                if(s<front[i] && front[i]<right && right<back[i]){  //extend the right side to consider 
                    right=back[i];
                    updateRight=true;
                }
            }
        }
        if(s==0 && right==l-1) return -1;
        return right;
    }


    int cal(int i,string &str){
        if(i==l) return 0;
        if(dp[i]!=-1) return dp[i];
        int s=i,e=back[str[i]-'a'];
        int take=0;
        int check=possible(s,e);
        if(check!=-1){
            take=1+cal(check+1,str);
        }
        int notake=cal(i+1,str);
        return dp[i]=max(take,notake);
    }


    bool maxSubstringLength(string s, int k) {
        l=s.length();
        memset(dp,-1,sizeof(dp));
        freq.assign(26,vector<int>(l+1,0));
        fill(front, front + 26, -1);
        fill(back, back + 26, l);
        for(int i=0;i<l;i++){
            if(front[s[i]-'a']==-1) front[s[i]-'a']=i;
            freq[s[i]-'a'][i+1]=1;
            for(int j=0;j<26;j++){
                freq[j][i+1]+=freq[j][i];
            }
        }
        for(int i=l-1;i>=0;i--){
            if(back[s[i]-'a']==l) back[s[i]-'a']=i;
        }
        int cnt=cal(0,s);
        return cnt>=k;
    }
};