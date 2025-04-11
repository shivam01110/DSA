#include <bits/stdc++.h>
using namespace std;

int solve(int n,int k,vector<int>& a){
    sort(a.begin(),a.end());
    int l=0,uni=0,prev=0,res=0,r=0;
    while(l<n && r<n){
        if(l==r) uni=1,prev=a[l];
        while(r<n && uni<=k && (a[r]-prev)<=1){
            if(a[r]!=prev) uni++;
            prev=a[r];
            if(uni<=k)r++;
        }
        res=max(res,r-l);
        int left=a[l];
        while(l<n && a[l]==left){
            l++;
        }
        uni--;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<solve(n,k,a)<<endl;
    }
    return 0;
}