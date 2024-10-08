#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int xpowy(long base,int exponent){
    long res=1;
    while(exponent){
        if(exponent & 1){
            res*=base;
            res%=mod;
        }
        base*=base;
        base%=mod;
        exponent>>=1;
    }
    return res;
}

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    if(multiplier==1) return nums;
    int n=nums.size();
    long maxi=*max_element(nums.begin(),nums.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({nums[i],i});
    }
    //do the simulation until min(nums)<=max(nums)
    while(k && 1LL*pq.top().first*multiplier<=maxi){
        int i=pq.top().second;
        pq.push({(nums[i]*multiplier)%mod,i});
        pq.pop();
        k--;
    }
    //now each element in nums will get multiplied by multiplier,(k/n) times in cycle
    const long pow=xpowy(multiplier,k/n);   
    while(!pq.empty()){
        int val=pq.top().first;
        int ind=pq.top().second;
        pq.pop();
        nums[ind]=(1LL*pow*val)%mod;
        if(k%n){    //if there remainder it means nums[ind] will get multiplied with multiplier once more
            k--;
            nums[ind]=(1LL*nums[ind]*multiplier)%mod; 
        }
    }
    return nums;
}

int main(){
    cout<<xpowy(3,5)<<endl;
    return 0;
}