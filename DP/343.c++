#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    int ans=0;
    for(int i=2;i<=n;i++){
        int rem=n%i;
        int quo=n/i;
        ans=max(ans,int(pow(quo,i-rem)*pow(quo+1,rem)));
    }
    return ans;
}

int main(){
    int n;cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}