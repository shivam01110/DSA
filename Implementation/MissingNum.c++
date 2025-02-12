#include <bits/stdc++.h>
using namespace std;

int solve(){
    long long n,j;
    cin>>n;
    long long tot=(n*(n+1))/2;
    for(int i=1;i<n;i++){
        cin>>j;
        tot-=j;
    }
    return tot;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}