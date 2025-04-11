#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int greaterCount(multiset<int>& arr,int val){
        auto it=arr.upper_bound(val);
        return distance(it,arr.end());
    }
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int l=0,r=n-1;
        multiset<int> arr1,arr2;
        res[l++]=nums[0];
        res[r--]=nums[1];
        arr1.insert(nums[0]);
        arr2.insert(nums[1]);
        for(int i=2;i<n;i++){
            int cnt1=greaterCount(arr1,nums[i]);
            int cnt2=greaterCount(arr2,nums[i]);
            if(cnt1>cnt2){
                res[l++]=nums[i];
                arr1.insert(nums[i]);
            }
            else if(cnt1<cnt2){
                res[r--]=nums[i];
                arr2.insert(nums[i]);
            }
            else{
                if(l<=n-r-1){
                    res[l++]=nums[i];
                    arr1.insert(nums[i]);
                }
                else{
                    res[r--]=nums[i];
                    arr2.insert(nums[i]);
                }
            }
        }
        reverse(res.begin() + l, res.end());
        return res;
    }
};