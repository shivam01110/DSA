#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& card,int itr,vector<int>& seq,int n){
    int maxi=card[seq[0]-1][itr];
    for(int i=1;i<n;i++){
        if(card[seq[i]-1][itr]<maxi){
            return false;
        }
        else maxi=card[seq[i]-1][itr];
    }
    return true;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> card(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>card[i][j];
        }
    }
    for(int i=0;i<n;i++){
        sort(card[i].begin(),card[i].end());
    }
    vector<int> seq(n,-1);
    for(int i=0;i<n;i++){
        if(0<=card[i][0] && card[i][0]<n){
            seq[card[i][0]]=i+1;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=1;i<m;i++){
        if(!(check(card,i,seq,n))){
            cout<<-1<<endl;
            return ;
        }
    }
    for(int i=0;i<n;i++){
        cout<<seq[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}