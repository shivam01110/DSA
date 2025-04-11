#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void MaximumPalindromeLengthFromIndexi(vector<int>& m,string s,int len){
        vector<vector<bool>> palin(len,vector<bool>(len,0));
        //iterate on top side of main diagonal along all diagonal
        for(int col=0;col<len;col++){
            int c=col;
            for(int r=0;r<len&&c<len;r++,c++){
                if(s[r]==s[c] && ((c-r+1<=2)||(palin[r+1][c-1]))){
                    palin[r][c]=1;
                    m[r]=max(m[r],c-r+1);
                }
            }
        }
    }

    int longestPalindrome(string s, string t) {
        reverse(t.begin(),t.end());
        int len1=s.length(),len2=t.length();
        //store the length of longest palindrome substring starting from each index
        vector<int> m(len1+1,0);    //size of m is len+1 handle corner case in line 38 when i==len1;
        vector<int> n(len2+1,0);    //size of n is len+1 handle corner case in line 38 when j==len2;
        MaximumPalindromeLengthFromIndexi(m,s,len1);
        MaximumPalindromeLengthFromIndexi(n,t,len2);
        int res=0;
        for(int i=0;i<=len1;i++) res=max(res,m[i]);
        for(int i=0;i<=len2;i++) res=max(res,n[i]);
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        int len=0;
        //find the longest common substring and update the res accordingly
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    len=2*dp[i][j]+max(m[i],n[j]);//take the maximum palindromic substring length starting from i in s or from j in t
                    res=max(res,len);
                }
            }
        }
        return res;
    }
};