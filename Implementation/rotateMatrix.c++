#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void print(vector<vector<char>>& matrix){
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    vector<vector<char>> RotateMatrixBy90deg(vector<vector<char>>& matrix){
        int r=matrix.size(),c=matrix[0].size();
        vector<vector<char>> transform(c,vector<char>(r,'.'));
        for(int i=0;i<r;i++){
            int col=r-i-1,row=c-1;
            for(int j=c-1;j>=0;j--){
                if(matrix[i][j]=='*'){
                    transform[j][col]='*';
                    row=j-1;
                }
                else if(matrix[i][j]=='#'){
                    transform[row][col]='#';
                    row--;
                }
                else continue;
            }
        }
        return transform;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> input={{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};
    vector<vector<char>> output=sol.RotateMatrixBy90deg(input);
    cout<<"input"<<endl;
    sol.print(input);
    cout<<"output"<<endl;
    sol.print(output);
    return 0;
}