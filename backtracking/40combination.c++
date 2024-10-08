#include <bits/stdc++.h>
using namespace std;


void recurr (int ind,vector<int>& nums,vector<int> temp,int sum,vector<vector<int>>& ans){
    if(sum==0) {ans.push_back(temp); return;}
    for(int j=ind;j<nums.size();j++){
        if(j>ind && nums[j]==nums[j-1]) continue;
        if(nums[j]>sum) break;
        temp.push_back(nums[j]);
        recurr(j+1,nums,temp,sum-nums[j],ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> temp;
    vector<vector<int>> res;
    recurr(0,candidates,temp,target,res);
    return res;
}

int main(){
    vector<int> nums={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> ans=combinationSum2(nums,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}