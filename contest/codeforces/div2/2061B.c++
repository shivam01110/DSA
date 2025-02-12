#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll t,n,a[200001];

void solve(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    a[0]=0;
    sort(a+1,a+n+1);
    ll eq[2]={-1};
    int ind_eq=0,diff=0;
    for(ll i=1;i<n;i++){
        diff=a[i+1]-a[i];
        if(diff==0){
            eq[ind_eq]=i;
            ind_eq++;
            i++;
        }
        if(ind_eq==2){
            cout<<a[eq[0]]<<" "<<a[eq[0]]<<" "<<a[eq[1]]<<" "<<a[eq[1]]<<endl;
            return;
        }
    }
    if(ind_eq==0){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<eq[0]-1;i++){
        diff=a[i+1]-a[i];
        if(a[eq[0]]>=(diff+2)/2){
            cout<<a[eq[0]]<<" "<<a[eq[0]]<<" "<<a[i]<<" "<<a[i+1]<<endl;
            return;
        }
    }
    if(eq[0]+2<=n && eq[0]-1>=1){
        diff=a[eq[0]+2]-a[eq[0]-1];
        if(a[eq[0]]>=(diff+2)/2){
            cout<<a[eq[0]-1]<<" "<<a[eq[0]]<<" "<<a[eq[0]]<<" "<<a[eq[0]+2]<<endl;
            return;
        }
    }
    for(int i=eq[0]+2;i<n;i++){
        diff=a[i+1]-a[i];
        if(a[eq[0]]>=(diff+2)/2){
            cout<<a[eq[0]]<<" "<<a[eq[0]]<<" "<<a[i]<<" "<<a[i+1]<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}


int main(){
    scanf("%lld",&t);
    while(t--){
        solve();
    }
    return 0;
}
