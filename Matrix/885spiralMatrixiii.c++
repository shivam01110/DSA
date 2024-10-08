#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> traversal;
    int cnt=1,d=0;
    int r=1;    //side of the matrix
    traversal.push_back({rStart,cStart});
    int lastRow=rStart,lastCol=cStart;
    while(cnt<rows*cols){
        for(int j=0;j<2;j++){
            for(int i=0;i<r;i++){
                lastRow+=dir[d].first;
                lastCol+=dir[d].second;
                if(0<=lastRow && lastRow<rows && 0<=lastCol && lastCol<cols){
                    traversal.push_back({lastRow,lastCol});
                    cnt++;
                }
            }
            d=(d+1)%4;
        }
        r++;
    }
    return traversal;
}