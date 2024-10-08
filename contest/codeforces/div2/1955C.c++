#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll> 

double log_base(double b, double a) {
    // Compute the logarithm of b to the base a using natural logarithms
    return log(b) / log(a);
}

void solve(){
    int n;cin>>n;
    vl a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll res=0;
    int i=0,p=1;
    for(int j=1;j<n;j++){
        if(a[j]<pow(a[i],p)){
            if(a[j]==1){
                cout<<-1<<endl;
                return;
            }
            else{
                int t=1;
                while(pow(a[i],p)>pow(a[j],t)){
                    res++;
                    t*=2;
                }
                i=j;p=t;
            }
        }
        else{
            i=j;p=1;
        }
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
