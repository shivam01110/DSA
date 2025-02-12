#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> prime;
    void seive(){
        vector<int> mark(1001,1);
        mark[0]=0,mark[1]=0;
        for(int i=2;i<1001;i++){
            if(mark[i]){
                for(int j=i*i;j<1001;j=j+i){
                    mark[j]=0;
                }
            }
        }
        for(int i=0;i<1001;i++){
            if(mark[i]) prime.push_back(i);
        }
    }
    int GreatestProperDivisor(int num){
        for(int i=0;i<prime.size() && prime[i]<=num/2;i++){
            if(num%prime[i]==0) return prime[i];
        }
        return -1;
    }
    int minOperations(vector<int>& nums) {
        seive();
        int op=0,r=nums.size()-1;
        while(r>=0){
            if(r==nums.size()-1 || nums[r]<=nums[r+1]){
                r--;
            }
            else{
                int div=GreatestProperDivisor(nums[r]);
                if(div==-1) return -1;
                op++;
                nums[r]=div;
            }
        }
        return op;
    }
};

int main(){
    Solution sol;
    cout<<sol.GreatestProperDivisor(2)<<endl;
    return 0;
}