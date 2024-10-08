#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> constructArray(int n, int k) {
    int i=0,maxi=INT_MIN,plus=1;
    vector<int> ans(n,0);
    ans[i]=1;
    i++;
    while(k>0){
        if(plus){
            ans[i]=ans[i-1]+k;
            maxi=max(ans[i],maxi);
        }
        else{
            ans[i]=ans[i-1]-k;
        }
        i++;
        k--;
        plus=1-plus;
    }
    if(i<n)ans[i]=maxi+1;
    i++;
    while(i<n){
        ans[i]=ans[i-1]+1;
        i++;
    }
    print(ans);
    return ans;
}

int main(){
    int n,k;cin>>n>>k;
    constructArray(n,k);
    // vector<int> ans=constructArray(n,k);
    // print(ans);
    return 0;
}