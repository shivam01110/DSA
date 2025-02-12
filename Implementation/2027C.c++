#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(){
    int n;
    cin>>n;
    map<ll,int> m1;
    map<ll,int> m2;
    ll a=0;
    m1[a]=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(i>1){
            a+=i-1;
            m1[a]=i-1;
        }
    }
    ll res=n;
    m2[res]=1;
    for(auto it=m1.begin();it!=m1.end();it++){
        if(m2[it->first]){
            m2[it->first+it->second]=1;
            res=max(res,it->first+it->second);
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}