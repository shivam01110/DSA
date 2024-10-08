#include <bits/stdc++.h>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n=arr.size();
    vector<vector<int>> prefix(n+1,vector<int>(35,0));   
    for(int i=0;i<n;i++){
        int num=arr[i];
        int j=0;
        while(num){
            prefix[i+1][j]=prefix[i][j]+(num&1);
            j++;
            num>>=1;
        }
        for(;j<35;j++){
            prefix[i+1][j]=prefix[i][j];
        }
    }
    vector<int> res;
    for(auto q:queries){
        int l=q[0]+1,r=q[1]+1;
        int subqueryXor=0;
        for(int i=0;i<35;i++){
            int cnt1=prefix[r][i]-prefix[l-1][i];
            if(cnt1%2){
                subqueryXor+=(2<<i);
            }
        }
        res.push_back(subqueryXor/2);
    }
    return res;
}