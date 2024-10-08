#include <bits/stdc++.h>
using namespace std;

int solve(int ind,int M,int turn,vector<int>& piles,vector<vector<vector<int>>>& dp){
    if(ind>piles.size()-1) return 0;
    if(dp[ind][M][turn]!=-1) return dp[ind][M][turn];
    int stones=0,res=(turn)?INT_MIN:INT_MAX;
    for(int j=1;j<=2*M && ind+j-1<piles.size();j++){
        stones+=piles[ind+j-1];
        if(turn){
            res=max(res,stones+solve(ind+j,max(M,j),!turn,piles,dp));  //take maximum when its Alice turn
        }
        else{
            res=min(res,solve(ind+j,max(M,j),!turn,piles,dp)); //take minimum when its Bob turn(opponent)
        }
    }
    return dp[ind][M][turn] = res;
}

int stoneGameII(vector<int>& piles) {
    int n=piles.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
    return solve(0,1,1,piles,dp);
}

int main(){
    vector<int> piles={2,7,9,4,4};
    cout<<stoneGameII(piles)<<endl;
    return 0;
}