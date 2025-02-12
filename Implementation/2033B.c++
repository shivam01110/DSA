#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        int r=0,c=i,mini=INT_MAX;
        while(r<n && c<n){
            mini=min(mini,matrix[r][c]);
            c++;
            r++;
        }
        res+=min(0,mini);
    }
    for(int j=1;j<n;j++){
        int r=j,c=0,mini=INT_MAX;
        while(r<n && c<n){
            mini=min(mini,matrix[r][c]);
            c++;
            r++;
        }
        res+=min(0,mini);
    }
    return abs(res);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}