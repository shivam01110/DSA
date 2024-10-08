#include <bits/stdc++.h>
using namespace std;

int solve(int n,int k){
    int cnt=0,temp=n,one=0;
    if(n==1) return 0;
    while(one<temp){
        n=n-k+1;
        one=one+k-1;
        if(n==1) one++;
        cnt++;
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}