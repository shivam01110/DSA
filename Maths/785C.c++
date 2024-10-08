#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define fl(i,n,inc) for(int i=0;i<n;i+=inc)
#define i int64_t
int64_t cal(i r,i d){
    int64_t tot=(d*(d+1))/2;
    return r-tot;
} 

void sol(){
    i n,m;
    cin>>n>>m;
    if(n<=m) cout<<n<<endl;
    i r=n-m;
    i l=0,h=r;
    i mid=0;
    while(l<h){
        mid=l+(h-l)/2;
        i extra=cal(r,mid);  //days after m day
        // if(extra==0){
        //     cout<<m+mid<<endl;
        //     return;
        // }
        if(extra>0){
            l=mid+1;
        }
        else{
            h=mid;
        }
        // cout<<mid<<endl;
    }
    cout<<m+l<<endl;
}
    
int main(){
    int t;cin>>t;
    while(t--)
    sol();
    return 0;
}