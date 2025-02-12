#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n<2){
        cout<<0<<endl;
        return;
    }
    cout<<2*(n-1)<<endl;
    for(int i=n-2;i>=0;i--){
        cout<<arr[i+1]<<" "<<arr[i]<<endl;
        cout<<arr[i]<<" "<<arr[i+1]<<endl;
    }
}

int main(){
    solve();
    return 0;
}