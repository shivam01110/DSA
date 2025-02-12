#include <bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,-1);
    for(int i=0;i<n;i++){
        if(nums[i]==2) continue;
        int temp=nums[i],l=0,mini=INT_MAX;
        while(temp){
            // Try unsetting a single bit from nums[i].
            if(temp&1){
                int n1=nums[i]^(1<<l),n2=n1+1;  
                if((n1|n2)==nums[i]) mini=min(n1,mini);
            }
            l++;
            temp>>=1;
        }
        res[i]=mini;
    }   
    return res;
}

int main(){
    vector<int> arr={2,5,7};
    vector<int> res=minBitwiseArray(arr);
    for(int i:res){
        cout<<i<<" ";
    }
    cout<<endl<<(1<<0)<<endl;
    return 0;
}