#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define fl(i,n,inc) for(int i=0;i<n;i+=inc)
void sol(){
    int n,i=0;
    cin>>n;
    vll a(n),diff;
    diff.push_back(0);
    ll maxi=LLONG_MIN;
    fl(i,n,1){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        if(a[i]<maxi) {
            diff.push_back(maxi-a[i]);
        }
    }
    sort(diff.begin(),diff.end());
    ll coins=0;int len=diff.size();
    for(int i=1;i<len;i++){
        ll curr=(len-i+1)*(diff[i]-diff[i-1]);
        coins+=curr;
    }
    cout<<coins<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)
    sol();
    return 0;
}