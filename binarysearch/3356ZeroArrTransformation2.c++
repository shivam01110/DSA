#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums,vector<vector<int>>& q,int k){
        if(k==0){
            for(int n:nums){
                if(n>0) return false;
            }
            return true;
        }
        map<int,int> m;
        for(int i=0;i<k;i++){
            m[q[i][0]]+=q[i][2];
            m[q[i][1]+1]-=q[i][2];
        }
        int n=nums.size();
        auto it=m.begin();
        int s=it->first,dec=it->second;
        //if any element >0 before the starting interval, then return false
        for(int i=0;i<s;i++){   
            if(nums[i]>0) return false;
        }
        it++;
        while(it!=m.end()){
            int e=it->first;
            int maxi=INT_MIN;
            //if any element >dec int the interval [s,e), then return false
            for(int i=s;i<e;i++){
                maxi=max(nums[i],maxi);
                if(maxi>dec) return false;
            }
            s=e;
            dec+=it->second;
            it++;
        }
        //if any element >0 after the last interval, then return false
        for(int i=s;i<n;i++){
            if(nums[i]>0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=-1,len=queries.size();
        int low=0,high=len;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,queries,mid)){
                ans=mid;
                high=mid-1; //look for smaller value
            }
            else{
                low=mid+1;  //look for higher value
            }
        }
        return ans;
    }
};