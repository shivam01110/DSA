#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long minimumOperations(vector<int>& nums, vector<int>& target) {
    int len=nums.size();
    ll operations=0;
    for(int i=0;i<len;i++){
        nums[i]=target[i]-nums[i];
    }
    operations=abs(nums[0]);
    for(int i=1;i<len;i++){
        if((nums[i]<0 && nums[i-1]>0)||(nums[i]>0 && nums[i-1]<0)){
            operations+=abs(nums[i]);
        }
        else{
            if(abs(nums[i])>abs(nums[i-1])){
                operations+=abs(nums[i])-abs(nums[i-1]);
            }
        }
    }
    return operations;
}