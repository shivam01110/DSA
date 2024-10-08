#include <bits/stdc++.h>
using namespace std;

int recurr(int i,int l,int p1,int p2,vector<int>& nums,int& k){
    if(l>2*k) {
        cout<<(p1^p2)<<endl;
        return p1^p2;
    }
    if(i>=nums.size()) return 0;
    int res=INT_MIN;
    res=max(res,recurr(i+1,l,p1,p2,nums,k));  //not-take
    if(l<=k){
        res=max(res,recurr(i+1,l+1,p1|nums[i],p2,nums,k));  //take
    }
    else{
        res=max(res,recurr(i+1,l+1,p1,p2|nums[i],nums,k));  //take
    }
    cout<<i<<endl;
    return res;
}

int maxValue(vector<int>& nums, int k) {
    int l=1,p1=0,p2=0;
    return recurr(0,l,p1,p2,nums,k);   
}

int main(){
    vector<int> nums={2,6,7};
    int k=1;
    cout<<maxValue(nums,k)<<endl;
    return 0;
}