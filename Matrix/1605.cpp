#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int r=rowSum.size(),c=colSum.size();
    vector<vector<int>> res(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int minele=min(rowSum[i],colSum[j]);
            res[i][j]=minele;
            rowSum[i]-=minele;
            colSum[j]-=minele;
        }
    }
    return res;
}