#include <bits/stdc++.h>
using namespace std;

int cnt=0;
int calOr(vector<int>& temp){
    int res=0;
    for(auto t:temp) res|=t;
    return res;
}
void help(int i,vector<int>& temp,vector<int>& nums,int req){
    if(i>=nums.size()){
        if(calOr(temp)==req) cnt++;
        return;
    }
    //take
    temp.push_back(nums[i]);
    help(i+1,temp,nums,req);
    //not-take
    if(!temp.empty()) temp.pop_back();
    help(i+1,temp,nums,req);
}

int main(){
    vector<int> temp={},nums={3,2,1,5};
    int req=0;
    for(auto t:nums) req|=t;
    help(0,temp,nums,req);
    cout<<cnt<<endl;
    return 0;
}