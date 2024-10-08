#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string arr;
    cin>>arr;
    int sum=0,i=0,len=0;
    while(i<n){
        if(arr[i]=='1'){
            sum++;
            len++;
            i++;
        }
        else{
            while(i<n && arr[i]=='0'){
                i++;
            }
            len++;
        }
    }
    if(sum>len/2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}