#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> mat(n);
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    int row=0;
    for(int i=0;i<n;i++){
        int cal=0;
        for(int j=0;j<m;j++){
            cal+=(mat[i][j]=='1');
        }
        if(cal%2) row++;
    }
    int col=0;
    for(int i=0;i<m;i++){
        int cal=0;
        for(int j=0;j<n;j++){
            cal+=(mat[j][i]=='1');
        }
        if(cal%2) col++;
    }
    cout<<max(row,col)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}