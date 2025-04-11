#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<bool> mark(200001,0);

bool possible(vector<int>& a,int& n,int& k,int& req){
    int part=0;
    int currmex=0;
    for(int i=0;i<n;i++){
        if(a[i]<=n+1)mark[a[i]]=1;
        while (mark[currmex]){
            currmex++;
        }
        if(currmex>=req){
            part++;
            currmex=0;
            for(int i=0;i<min(n+2,req+1);i++){
                mark[i]=0;
            }
        }
    }
    for(int j=0;j<n+2;j++){
        mark[j]=0;
    }
    return (part>=k);
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,h=200001;
    int res=0;
    while(h-l>1){
        int mid=l+(h-l)/2;
        if(possible(a,n,k,mid)){
            res=mid;
            l=mid;
        }
        else{
            h=mid;
        }
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}