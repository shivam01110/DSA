#include <bits/stdc++.h>
using namespace std;

int minChanges(int n, int k) {
    int cnt=0;
    while (n!=0 && k!=0)
    {
        if(n%2 && k%2==0) cnt++;
        if(n%2==0 && k%2) return -1;
        n/=2;k/=2;
    }
    if(n==0 && k!=0) return -1;
    while(n!=0){
        if(n%2) cnt++;
        n/=2;
    }
    return cnt;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<minChanges(n,k)<<endl;
    return 0;
}