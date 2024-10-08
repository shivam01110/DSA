#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int>& nums) {
    int n=nums.size();
    int n=nums.size();
    if(n<=3) return 0;
    sort(nums.begin(),nums.end());
    int res=INT_MAX;
    for(int i=0;i<4;i++){
        res=min(res,(nums[n-4+i]-nums[i]));
    }
    return res;
}

int main(){
    vector<int> nums={5,3,2,};
    cout<<minDifference(nums);
    return 0;
}