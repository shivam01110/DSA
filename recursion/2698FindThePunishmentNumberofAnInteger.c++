#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isPossible(int i,int len,string& sq,int num,int sum,bool ans){
        if(i==len) return sum==num;
        for(int j=1;j<=len-i;j++){
            ans=ans|isPossible(j+i,len,sq,num,sum+stoi(sq.substr(i,j)),ans);
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
            int squrare=i*i;
            string sq=to_string(squrare);
            if(isPossible(0,sq.length(),sq,i,0,false)) res+=i;
        }
        return res;
    }
};