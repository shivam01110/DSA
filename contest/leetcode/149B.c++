#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> diff(n,0);
        diff[0]=startTime[0]-0;
        diff[n-1]=eventTime-endTime[n-1];

        for(int i=0;i<n-1;i++){
            diff[i+1]=startTime[i+1]-endTime[i];
        }
        int l=0,r=0;
        int ans=0,sum=0;
        if(k==n){
            for(auto d:diff){
                ans+=d;
                return ans;
            }
        }
        while(r<n){
            sum+=diff[r];
            if(r-l==k){
                ans=max(ans,sum);
                sum-=diff[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};