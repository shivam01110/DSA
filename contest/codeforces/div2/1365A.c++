#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int validRow=n,validCol=m;
    vector<int> row(n,0);   //invalid row
    vector<int> col(m,0);   //invalid col
    vector<vector<int>> grid(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]){
                if(row[i]==0)validRow--;
                if(col[j]==0)validCol--;
                row[i]=1;
                col[j]=1;
            }
        }
    }
    int turn=min(validCol,validRow);
    if(turn%2) cout<<"Ashish"<<endl;
    else cout<<"Vivek"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}