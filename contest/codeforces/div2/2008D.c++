#include <bits/stdc++.h>
using namespace std;

void solve2(){
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    string s;
    cin>>s;
    vector<int> vis(n+1,0);
    vector<int> par(n+1,0);
    vector<int> child(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[arr[i]]){
            int cnt=0;
            if(s[i-1]=='0') cnt++;
            int parent=arr[i];
            int next=arr[i];
            vis[parent]=1;
            while(arr[next]!=parent){
                if(s[next-1]=='0') cnt++;
                next=arr[next];
                par[next]=parent;
                vis[next]=1;
            }
            par[parent]=parent;
            child[parent]=cnt;
        }
        cout<<child[par[arr[i]]]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve2();
    }
    return 0;
}
 
