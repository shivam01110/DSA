#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurr(int i,int posY1,int posX2,int n,vector<vector<int>>& fruits,vector<vector<vector<int>>>& dp){
        //child 3 and child 2 should not go above and left of child 1 respectively in order to move to (n-1,n-1) in (n-1) steps
        if(posY1<i || posY1>=n || posX2<i || posX2>=n) return INT_MIN;  
        if(i==n-1){
            if(posX2==n-1 && posY1==n-1) return fruits[n-1][n-1];
            return INT_MIN;
        }
        if(dp[i][posY1][posX2]!=-1) return dp[i][posY1][posX2];
        int res=INT_MIN;
        int choco=fruits[i][i];
        if(posY1!=i )choco+=fruits[i][posY1];   //children 1 and children 2 are at different position
        if(posX2!=i) choco+=fruits[posX2][i];   //children 1 and children 3 are at diffent position
        for (int delta1 = -1; delta1 <= 1; delta1++) { // Moves for posY1
            int newY1 = posY1 + delta1;
            for (int delta2 = -1; delta2 <= 1; delta2++) { // Moves for posX2
                int newX2 = posX2 + delta2;
                res = max(res, choco + recurr(i + 1,newY1,newX2,n,fruits,dp));
            }
        }
        return dp[i][posY1][posX2]=res;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res=-1,n=fruits.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return recurr(0,n-1,n-1,n,fruits,dp);
    }
};


//optimal way to solve this question using 2 2D dp,solve  for the child at (0,n-1) and (n-1,0) separately
class Solution1 {
public:
    // The thing is that for the child start at (0, 0), he can only go to (i + 1, j + 1) from (i, j).
    int solve1(int x,int n,vector<vector<int>>& fruits){
        //First child go a straight line to (n - 1, n - 1).
        int choco=0;
        for (int i=x;x<n;x++) { 
            choco+=fruits[x][x];
        }
        return choco;
    }
    // Bottom  and left child take a DP for the bottom left part of the fruits.
    // For the child start at(n - 1, 0), he cannot cross the line of "i = j", or they have no time to turn back to (n - 1, n - 1).
    int solve2(int x,int y,int n,vector<vector<int>>& fruits,vector<vector<int>>& dp){
        if(x>=n || y<n/2 || y>=n) return INT_MIN;
        if(x==n-1 && y==n-1) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int choco=0,res=INT_MIN;
        if(x!=y) choco+=fruits[x][y];
        for (int delta1 = -1; delta1 <= 1; delta1++) { // Moves for child 2
            int newY = y + delta1;
            res = max(res, choco + solve2(x+1,newY,n,fruits,dp));
        }
        return dp[x][y]=res;
    }
    // So as the third child start at (0, n - 1).
    // Thus, three child are indepent actually.
    int solve3(int x,int y,int n,vector<vector<int>>& fruits,vector<vector<int>>& dp){
        if(y>=n || x<n/2 || x>=n) return INT_MIN;
        if(x==n-1 && y==n-1) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int choco=0,res=INT_MIN;
        if(x!=y) choco+=fruits[x][y];
        for (int delta1 = -1; delta1 <= 1; delta1++) { // Moves for child 3
            int newX = x + delta1;
            res = max(res, choco + solve3(newX,y+1,n,fruits,dp));
        }
        return dp[x][y]=res;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res=0,n=fruits.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1));
        vector<vector<int>> dp2(n,vector<int>(n,-1));
        res=solve1(0,n,fruits);
        res+=solve2(0,n-1,n,fruits,dp1);
        res+=solve3(n-1,0,n,fruits,dp2);
        return res;
    }
};