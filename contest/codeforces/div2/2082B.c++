#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    unordered_map<int, int> dp1[32][32];
    unordered_map<int, int> dp2[32][32];
    int mini(int x,int n,int m){
        if(x==0 || (n==0 && m==0)) return x;
        if (dp1[n][m].count(x)) return dp1[n][m][x];
        int res=INT_MAX;
        if(n>0) res=min(res,mini(x/2,n-1,m));
        if(m>0){
            if(x%2) x+=2;
            res=min(res,mini(x/2,n,m-1));
        }
        return dp1[n][m][x]=res;
    }
    
    
    int maxi(int x,int n,int m){
        if(x==0 || (n==0 && m==0)) return x;
        int res=INT_MIN;
        if (dp2[n][m].count(x)) return dp2[n][m][x];
        if(n>0) res=max(res,mini(x/2,n-1,m));
        if(m>0){
            if(x%2) x+=2;
            res=max(res,mini(x/2,n,m-1));
        }
        return dp2[n][m][x]=res;
    }

};





void solve(){
    int x,n,m;
    cin>>x>>n>>m;
    ll tot=n+m;
    int a=0,b=0;
    if(tot<=32){
        Solution sol;
        a=sol.mini(x,n,m);
        b=sol.maxi(x,n,m);
    }
    cout<<a<<" "<<b<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}