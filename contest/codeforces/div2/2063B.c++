#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int s=r-l+1;
    vector<int> arr1;
    vector<int> arr2;
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        if(i<r) arr1.push_back(ele);
        if(i>=l-1) arr2.push_back(ele);
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    ll sum1=0,sum2=0;
    for(int i=0;i<s;i++){
        sum1+=arr1[i];
        sum2+=arr2[i];
    }
    cout<<min(sum1,sum2)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}