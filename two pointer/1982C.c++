#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int left=0,right=0;
    ll sum=0,cnt=0;
    while(right<n){
        sum+=a[right];
        //while sum>r move the left pointer and adjust the sum
        while(sum>r){
            sum-=a[left];
            left++;
        }
        //if l<=sum<=r then set sum=0 and move left pointer = right pointer i.e left=right+1,
        //so that left and right will point to same index in next iteration
        if(sum>= l && sum<=r){
            cnt++;
            left=right+1;
            sum=0;
        }
        right++;
    }
    cout<<cnt<<endl;
}

int main(){
    int t;cin>>t;
    while(t--) solve();
    return 0;
}