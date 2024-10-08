#include <bits/stdc++.h>
using namespace std;
#define ll long long


//time-->n^2 space-->n
ll recurr(int i,vector<int>& nums,vector<ll>& dp){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    ll maxi=LLONG_MIN,part=0;
    ll p=0;
    for(;i<nums.size();i++){
        part+=(pow(-1,p))*nums[i];
        p++;
        maxi=max(maxi,part+recurr(i+1,nums,dp));
    }
    return dp[i]=maxi;
}

//space->n*2*2, time--->n*2*2
ll solve(int i,int start,int sign,vector<int>& nums,vector<vector<vector<ll>>>& dp){
    if(i==nums.size()) return 0;
    if(dp[i][start][sign]!=-1e15) return dp[i][start][sign];
    ll res=-1e15;
    if(start){  //fresh start   
        res=max(res,nums[i]+solve(i+1,0,1,nums,dp));
    }
    else{   //contining
        res=max(res,(ll)pow(-1,sign)*nums[i]+solve(i+1,0,!sign,nums,dp));
        res=max(res,solve(i,1,0,nums,dp));
    }
    return dp[i][start][sign]=res;
}

long long maximumTotalCost(vector<int>& nums) {
    int n=nums.size();
    vector<ll> dp(n+1,-1);
    return recurr(0,nums,dp);
}

int main(){
    vector<int> nums={0};
    int n=nums.size();
    vector<ll> dp(n+1,-1);
    cout<<recurr(0,nums,dp)<<endl;
    return 0;
}