#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    int w=INT_MIN,wi;
    int h=INT_MIN,hi;
    for(int i=0;i<n;i++){
        cin>>wi>>hi;
        w=max(w,wi);
        h=max(h,hi);
    }
    return 2*(h+w);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}