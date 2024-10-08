#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colSum) {
    vector<int> rowSum={upper,lower};
    int r=rowSum.size(),c=colSum.size();
    vector<vector<int>> res(r,vector<int>(c,0));
    for(int j=0;j<c;j++){
        if(colSum[j]==2){
            colSum[j]=0;
            rowSum[0]--;
            rowSum[1]--;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int minele=min(rowSum[i],colSum[j]);
            res[i][j]=minele;
            rowSum[i]-=minele;
            colSum[j]-=minele;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(res[i][j]!=0){
                return {{}};
            }
        }
    }
    return res;
}