#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    long maxi=LONG_MIN;
    long ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        maxi=max(maxi,ele);
    }
    for(int i=0;i<m;i++){
        char c;int l,r;
        cin>>c>>l>>r;
        if(c=='+' && l<=maxi && maxi<=r){
            maxi++;
        }
        if(c=='-' && l<=maxi && maxi<=r){
            maxi--;
        }
        cout<<maxi<<" ";
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
