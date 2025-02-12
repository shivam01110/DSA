#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi=arr[0];
    ll res=0;
    for(int i=1;i<n;i++){
        if(arr[i]<=maxi){
            res+=(maxi-arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    cout<<res<<endl;
    return 0;
}