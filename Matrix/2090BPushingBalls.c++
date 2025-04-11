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
    vector<int> col(m);
    for(int i=0;i<n;i++){
        int row=0;
        for(int j=0;j<m;j++){
            col[j]+=mat[i][j]-'0';
            row+=mat[i][j]-'0';
            if(mat[i][j]=='1' && col[j]!=i+1 && row!=j+1){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}