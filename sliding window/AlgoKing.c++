#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr,int k,int n){
    map<int,int> m;
    int l=0,r=1,res=INT_MAX;
    while(r<n){
        m[abs(arr[r]-arr[r-1])]+=1;
        if(r-l+1==k){
            cout<<m.rbegin()->first<<endl;
            res=min(res,m.rbegin()->first);
            m[abs(arr[l]-arr[l+1])]-=1;
            if(m[abs(arr[l]-arr[l+1])]==0){
                m.erase(abs(arr[l]-arr[l+1]));
            }
            l++;
        }
        r++;
    }
    return res; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    cout<<solve(arr,k,n)<<endl;
    return 0;
}