#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        int n=A.size();
        vector<int> prefix(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(m[A[i]]==1){
                cnt++;
            }
            else{
                m[A[i]]=1;
            }
            if(m[B[i]]==1){
                cnt++;
            }
            else{
                m[B[i]]=1;
            }
            prefix[i]=cnt;
        }
        return prefix;
    }
};