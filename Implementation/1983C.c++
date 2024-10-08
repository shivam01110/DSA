#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
void print(vector<int>& ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int solve(vll& a,vll& b,vll& c,vector<int>& ans){
    int s=a.size();
    int req=(a.back()+2)/3;
    int la=1;
    int ra=lower_bound(a.begin()+1,a.end(),req)-a.begin();
    if(ra>=s-1) return 0;
    int lb=ra+1;
    int req2=b[ra]+req;
    int rb=lower_bound(b.begin()+1,b.end(),req2)-b.begin();
    if(rb>=s-1) return 0;
    int lc=rb+1;
    int req3=c[rb]+req;
    // int rc=lower_bound(c.begin()+1,c.end(),req3)-c.begin();
    // if(rc==s) return 0;
    if(c[s-1]<req3) return 0;
    ans={la,ra,lb,rb,lc,s-1};
    return 1;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll a(n+1,0);
        vll b(n+1,0);
        vll c(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
            b[i]+=b[i-1];
        }
        for(int i=1;i<=n;i++){
            cin>>c[i];
            c[i]+=c[i-1];
        }
        vector<int> ans;
        if(solve(a,b,c,ans)){
            print(ans);
        }
        else if(solve(a,c,b,ans)){
            swap(ans[2],ans[4]);
            swap(ans[3],ans[5]);
            print(ans);
        }
        else if(solve(b,c,a,ans)){
            swap(ans[2],ans[4]);
            swap(ans[3],ans[5]);
            swap(ans[0],ans[2]);
            swap(ans[1],ans[3]);
            print(ans);
        }
        else if(solve(b,a,c,ans)){
            swap(ans[0],ans[2]);
            swap(ans[1],ans[3]);
            print(ans);
        }
        else if(solve(c,a,b,ans)){
            swap(ans[0],ans[2]);
            swap(ans[1],ans[3]);
            swap(ans[4],ans[2]);
            swap(ans[5],ans[3]);
            print(ans);
        }
        else if(solve(c,b,a,ans)){
            swap(ans[0],ans[4]);
            swap(ans[1],ans[5]);
            print(ans);
        }
        else cout<<-1;
        cout<<endl;
    }
    return 0;
}