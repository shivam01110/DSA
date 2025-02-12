#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>


void putInSet(ll l,ll r,set<ll>& s){
    for(;l<=r;l++){
        s.insert(l);
    }
}
void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<ll> s;
    //left part of x
    ll pref1=0,mx1=0,mn1=0,L1=0,R1=0;
    int x=-1;
    for(int i=0;i<n;i++){
        if(abs(a[i])!=1){ 
            x=i;
            break;
        }
        pref1+=a[i];
        L1=min(L1,pref1-mx1);
        R1=max(R1,pref1-mn1);
        mn1=min(mn1,pref1);
        mx1=max(mx1,pref1);
    }
    putInSet(L1,R1,s);//all number in range [L1,R1] will be included in set
    if(x!=-1){
        ll l1=0,r1=0,tot=0;
        for(int i=x-1;i>=0;i--){
            tot+=a[i];
            l1=min(l1,tot);
            r1=max(r1,tot);
        }
        //right part of x
        ll pref2=0,mx2=0,mn2=0,L2=0,R2=0;
        for(int i=x+1;i<n;i++){
            pref2+=a[i];
            L2=min(L2,pref2-mx2);
            R2=max(R2,pref2-mn2);
            mn2=min(mn2,pref2);
            mx2=max(mx2,pref2);
        }
        putInSet(L2,R2,s);
        //for subset including x
        putInSet(min((ll)a[x],(ll)a[x]+l1+mn2),max((ll)a[x],(ll)a[x]+r1+mx2),s);
    }
    cout<<s.size()<<endl;
    for(auto it=s.begin();it!=s.end();it++) cout<<*(it)<<" ";
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