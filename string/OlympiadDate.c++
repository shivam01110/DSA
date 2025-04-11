#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;cin>>n;
    int ans=0;
    int cnt0=3,cnt1=1,cnt2=2,cnt3=1,cnt5=1;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==0) cnt0--;
        if(a==1) cnt1--;
        if(a==2) cnt2--;
        if(a==3) cnt3--;
        if(a==5) cnt5--;
        if(ans==0 && cnt0<=0 && cnt2<=0 &&  cnt1<=0 && cnt3<=0 && cnt5<=0){
            ans=i+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}