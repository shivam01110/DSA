// 3201. Find the Maximum Length of Valid Subsequence I

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int k){
    int n=nums.size();
    int ans=0;
    vector<vector<int>> rem(n,vector<int>(k,1));
    for(int i=1;i<n;i++){
        vector<int> temp(k,1);
        for(int j=i-1;j>=0;j--){
            int r=(nums[i]+nums[j]) %k;
            temp[r]=max(temp[r],rem[j][r]+1);
            ans=max(ans,temp[r]);
        }
        rem[i]=temp;
    }
    return ans;
}
int main(){
    // cout<<solve({2,39,23})<<endl;
    return 0;
}