#include <bits/stdc++.h>
using namespace std;

void solve(){
    int g;
    cin>>g;
    vector<int> a(g,0);
    vector<int> b(g,0);
    for(int i=0;i<g;i++){
        cin>>a[i];
    }
    for(int i=0;i<g;i++){
        cin>>b[i];
    }
    int g1=0,g2=0;
    int cnt1=0,cnt0=0,cnt_1=0;
    for(int i=0;i<g;i++){
        if(a[i]>b[i]) g1++;
        else if(a[i]<b[i]) g2++;
        else{
            if(a[i]==0) cnt0++;
            else if(a[i]==1) cnt1++;
            else cnt_1++;
        }
    }
    while(cnt_1>0){
        if(g1<=g2) g1++;
        else g2++;
        cnt_1--;
    }
    while(cnt1>0){
        if(g1>=g2) g1--;
        else g2--;
        cnt1--;
    }
    cout<<min(g1,g2)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}