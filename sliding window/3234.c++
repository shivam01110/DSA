#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length(),ans=0;
        vector<int> prefix(n,0); 
        if(s[0]=='1') prefix[0]=1; 
        for(int i=1;i<s.length();i++){
            if(s[i]=='1'){
                prefix[i]=prefix[i-1]+1;
            }
            else{
                prefix[i]=prefix[i-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len=j-i+1;
                int one=prefix[j];
                if(i!=0) one-=prefix[i-1];
                int zero=len-one;
                int diff=one-(zero*zero);
                if(diff<0) j+=abs(diff)-1;  //move j to j+=abs(diff)-1 and check in next iteration whether it will be dominant substring or not
                else{
                    ans++;
                    if(diff>0){
                        int extra=sqrt(one)-zero;   //we have extra one so we can move j to j+extra, it will a dominant substring
                        int nextj=j+extra;
                        if(nextj>=n){
                            ans+=(n-j-1);
                        }
                        else{
                            ans+=extra;
                        }
                        j=nextj;
                    }
                }
            }
        }
        return ans;
    }
};