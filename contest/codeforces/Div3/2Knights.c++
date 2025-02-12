#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll t=((i*i)*((i*i)-1))-8-24-16-((i-4)*16)-((i-4)*24)-((i-4)*(i-4)*8);
        cout<<max(0ll,t/2)<<endl;
    }
    return 0;
}