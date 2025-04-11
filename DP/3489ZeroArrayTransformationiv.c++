#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    //check if elements at i can be made 0
    bool solve(int ind,int num,int NumQue,int i,int sum,vector<vector<int>>& preprocessing,vector<vector<vector<int>>>& dp){
        if(i==NumQue) return (sum==num);
        if(num==sum) return true;
        if(dp[ind][i][sum]!=-1) return dp[ind][i][sum];
        bool res=false;
        res=res|solve(ind,num,NumQue,i+1,sum,preprocessing,dp);// do nothing
        if(sum+preprocessing[i][ind]<=num){
            res=res|solve(ind,num,NumQue,i+1,sum+preprocessing[i][ind],preprocessing,dp);   //consider element and add value
        }      
        return dp[ind][i][sum]=res;
    }
    bool isPossible(int n,int NumQue,vector<int>& nums,vector<vector<int>>& preprocessing){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(NumQue,vector<int>(1001,-1)));
        for(int i=0;i<n;i++){
            if(!solve(i,nums[i],NumQue,0,0,preprocessing,dp)) return false;
        }
        return true;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int len=nums.size();
        int l=0,h=queries.size();
        int res=-1;
        vector<vector<int>> preprocessing(h,vector<int>(len,0));
        for(int i=0;i<h;i++){
            int l=queries[i][0],r=queries[i][1],v=queries[i][2];
            for(int j=l;j<=r;j++){
                preprocessing[i][j]=v;
            }
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(len,mid,nums,preprocessing)){
                h=mid-1;
                res=mid;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};