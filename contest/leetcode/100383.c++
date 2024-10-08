#include <bits/stdc++.h>
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
    if(k==1) return nums;
    int n=nums.size();
    vector<int> inc(n,0),prefix(n,0),res;
    inc[0]=1;
    prefix[0]=1;
    for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]==1){
            inc[i]=1;
        }
        prefix[i]=prefix[i-1]+inc[i];
    }
    for(int i=k-1;i<n;i++){
        int t=prefix[i]-prefix[i-k+1]+1;
        if(t==k ||(t==k-1 && nums[i]-nums[i-k+1]==k-1)){
            res.push_back(nums[i]);
        }
        else{
            res.push_back(-1);
        }
    }
    return res;
}