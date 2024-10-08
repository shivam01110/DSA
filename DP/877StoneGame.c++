#include <bits/stdc++.h>
using namespace std;

bool solve(int l,int r,int turn,int alice,int bob,vector<int>& piles){
    if(l>r) return alice>bob;
    bool ans=false;
    if(turn%2){//alice turn
        ans|=solve(l+1,r,turn++,alice+piles[l],bob,piles);
        ans|=solve(l,r-1,turn++,alice+piles[r],bob,piles);
    }
    else{
        ans|=solve(l+1,r,turn++,alice,bob+piles[l],piles);
        ans|=solve(l,r-1,turn++,alice,bob+piles[r],piles);
    }
    return ans;
}

bool stoneGame(vector<int>& piles) {
    int l=0,r=piles.size()-1;
    return solve(l,r,1,0,0,piles);
}

int main(){
    vector<int> piles={3,7,2,3};
    cout<<stoneGame(piles)<<endl;
    return 0;
}