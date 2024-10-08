#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(){
    int n;cin>>n;
    vector<ll> a(n,0);
    string s;
    ll tot=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        tot+=a[i];
        a[i]=tot;
    }
    cin>>s;
    int l=0,r=n-1;long long ans=0;
    while(l<r){
        if(s[l]=='L' && s[r]=='R'){
            ans+=a[r];
            if(l!=0) ans-=a[l-1];
            l++;
            r--;
        }
        if(s[l]=='R') l++;
        if(s[r]=='L') r--;
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}