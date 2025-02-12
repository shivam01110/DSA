#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    ll sum=((n+1)*n)/2;
    if(sum%2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        ll req=sum/2;
        int p=n;
        vector<int> arr;
        for(;req>=p;){
            arr.push_back(p);
            req-=p;
            p-=2;
        }
        if(req>0) {arr.push_back(req);}
        sort(arr.begin(),arr.end());
        cout<<arr.size()<<endl;
        for(auto a:arr) cout<<a<<" ";
        cout<<endl;
        cout<<(n-arr.size())<<endl;
        p=0;
        for(int i=1;i<=n;i++){
            if(p<arr.size() && arr[p]==i) {p++;}
            else cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}