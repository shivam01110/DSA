#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        int n=nums.size();
        ll maxi=LLONG_MIN;
        nums[0]=nums[0]-k;
        maxi=max(maxi,(ll)nums[0]);
        m[nums[0]]=1;
        for(int i=1;i<n;i++){
            ll l=nums[i]-k,h=nums[i]+k;
            if(l<=maxi+1 && maxi+1<=h){ //l...maxi+1...h
                maxi=maxi+1;
                nums[i]=maxi;
            }
            else if(maxi+1<l){  //maxi+1...l...h
                maxi=l;
                nums[i]=l;
            }
            else{       // l...h...maxi+1
                continue;
            }
        }
        sort(nums.begin(),nums.end());
        int distinctElements=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) distinctElements++;
        }
        return distinctElements;
    }
};