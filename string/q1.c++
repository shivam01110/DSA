#include <bits/stdc++.h>
using namespace std;

bool recur(int i,int j,int m,int n,string& a,string& b,bool change){
    if(i>=m) return j==n;
    if(j>=n) return true;
    bool ans=false;
    if(a[i]==b[j]) ans|=recur(i+1,j+1,m,n,a,b,change);
    else{
        ans|=recur(i+1,j,m,n,a,b,change);   //skip change
        if(!change) ans|=recur(i+1,j+1,m,n,a,b,!change);    //do change if possible
    }
    return ans;
}

bool memo(int i,int j,int m,int n,string& a,string& b,bool change,vector<vector<vector<int>>>& dp){
    if(i>=m) return j==n;
    if(j>=n) return true;
    if(dp[i][j][change]!=-1) return dp[i][j][change];
    bool ans=false;
    if(a[i]==b[j]) ans|=memo(i+1,j+1,m,n,a,b,change,dp);
    else{
        ans|=memo(i+1,j,m,n,a,b,change,dp);   //skip change
        if(!change) ans|=memo(i+1,j+1,m,n,a,b,!change,dp);    //do change if possible
    }
    return dp[i][j][change]=ans;
}

int solve(string& a,string& b){
    int m=a.size(),n=b.size();
    for(int i=0;i<m;i++){
        if(a[i]==b[0] && recur(i+1,1,m,n,a,b,false)){
            return i+1;
        }
    }
    return -1;
}

int main(){
    string a="m",b="m";
    cout<<solve(a,b)<<endl;
}