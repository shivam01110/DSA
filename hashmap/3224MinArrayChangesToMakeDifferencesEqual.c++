#include <bits/stdc++.h>
using namespace std;

int minChanges(vector<int>& nums, int k) {
    unordered_map<int,int> m;
    int len=nums.size(),maxfreq=0,commDiff=INT_MAX,changes=0;
    for(int i=0;i<len/2;i++){
        int diff=abs(nums[i]-nums[len-i-1]);
        m[diff]++;
        if(m[diff]>=maxfreq){
            if(maxfreq==m[diff]){
                commDiff=min(diff,commDiff);
            }
            else commDiff=diff;
            maxfreq=m[diff];
            
        }
    }
    for(int i=0;i<len/2;i++){
        int diff=abs(nums[i]-nums[len-i-1]);
        if(diff!=commDiff){
            if(k-min(nums[i],nums[len-1-i])<commDiff || max(nums[i],nums[len-1-i])<commDiff){
                changes+=2;
            }
            else changes++;
        }
    }
    return changes;
}

int main(){ 
    vector<int> arr={4,10,9,0,3,11,12,3,7,11,7,13,5,3,6,4};int k=16;
    cout<<minChanges(arr,k)<<endl;
    return 0;
}