#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve(){
    int n;cin>>n;
    vector<ll> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    //1.sort the given array
    sort(arr.begin(),arr.end());
    int l=0,ans=INT_MAX;
    //2.if element between the index l and r are following the identity a[l]+a[l+1]>a[r] then
    // we can choose any 3 points between l and r and will able to make triangle with them
    // here number of operations is equalivalent to operation to applied on the element outside of 
    // the subarray [l,r],i.e n-(r-l+1) operation and we need to minimised this.
    for(int r=2;r<n;r++){
        while(r-l>=2 && arr[l]+arr[l+1]<=arr[r]) l++;
        ans=min(ans,n-(r-l+1));
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}