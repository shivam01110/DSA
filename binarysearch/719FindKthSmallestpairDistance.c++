#include <bits/stdc++.h>
using namespace std;

int smallestDistancePair(vector<int>& nums, int k) {
    int maxi=*max_element(nums.begin(),nums.end());
    vector<int> dis(maxi+1,0);
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            dis[abs(nums[j]-nums[i])]++;
        }
    }
    for(int i=0;i<maxi+1;i++){
        k-=dis[i];
        if(k<=0) return i;
    }
    return 0;
}


//using sliding window and binary search
int CountPairWithDiffD(vector<int>& nums,int d){
    int i=0,j=0,n=nums.size();
    int count=0;
    while(j<n){
        if(nums[j]-nums[i]<=d){
            count+=(j-i);
            j++;
        }
        else{
            i++;
        }
    }   
    return count;
}
int smallestDistancePair2(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int l=0,h=nums.back()-nums[0];
    while(l<=h){
        int mid=(l+h)/2;
        int pairs=CountPairWithDiffD(nums,mid);
        if(pairs<k){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return l;
}


int main(){
    vector<int> nums={1,3,1};
    cout<<smallestDistancePair2(nums,1);
    return 0;
}