//355B. Vasya and Public Transport 
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void solve(){
    int c1,c2,c3,c4,m,n;
    cin>>c1>>c2>>c3>>c4>>n>>m;
    vi a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i]; //bus
    for(int i=0;i<m;i++) cin>>b[i]; //trolley
    int pa=0,pb=0;//pa-->price for bus,pb-->price for trolley
    for(int i=0;i<n;i++){
        int c=min(c1*a[i],c2);
        pa=min(pa+c,c3);
    }
    for(int i=0;i<m;i++){
        int c=min(c1*b[i],c2);
        pb=min(pb+c,c3);
    }
    int ans=min(pa+pb,c4);
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}