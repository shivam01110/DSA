#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    for(int i=-k/2;i<=k/2;i++){
        if(i==0 && k%2==0) continue;
        cout<<x<<" "<<y+i<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}