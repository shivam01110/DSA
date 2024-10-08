#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n,steps) for(int i=0;i<n;i+=steps)
unordered_map<char,int> m={
{'T',4},
{'I',20},
{'O',8},
{'D',12},
{'C',6}
};
void solve(){
    int n,i=0;
    cin>>n;
    ll ans=0;
    string geo;
    f(i,n,1){
        cin>>geo;
        ans+=m[geo[0]];
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}