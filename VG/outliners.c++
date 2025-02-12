#include <bits/stdc++.h>
using namespace std;

#define ll long long

int outliners(vector<int> arr){
    int l=arr.size();
    ll sum=0;
    int res=-1;
    sort(arr.begin(),arr.end());
    for(auto n:arr) sum+=n;
    for(int i=0;i<l-1;i++){
        ll curr=sum-arr[i]-arr.back();
        if(curr==arr.back() && curr!=arr[i]) res=max(res,arr[i]);
    }
    ll curr=sum-arr.back()-arr[l-2];
    if(curr==arr[l-2]) res=max(res,arr.back());
    return res;
}

int main(){
    vector<int> arr={2,2,4,2};
    vector<int> arr2={4,1,2,1,10,3};
    cout<<outliners(arr)<<endl;
    cout<<outliners(arr2)<<endl;
    return 0;
}