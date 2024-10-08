//1856B. Good Arrays
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define vll vector<ll>
void solve(){
    int n;
    cin>>n;
    int cnt=0;  //count 1
    ll ele=0,sum=0;
    for(int i=0;i<n;i++){
        cin>>ele;
        sum+=ele;
        if(ele==1) cnt++;
    }
    if(sum<cnt+n || n==1) cout<<"NO"<<'\n';
    else cout<<"YES"<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}