// 3201. Find the Maximum Length of Valid Subsequence I

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums){
    int n=nums.size();
    int even=-1,odd=-1,last=0;   //index
    if(nums[0]%2) {odd=0;last=1;}
    else even=0;
    int l1=1,l2=1,l3=1;
    //l1=odd+even+odd+even+odd+...
    //l2=odd+odd+odd+odd+odd+...
    //l3=even+even+even+even+even+...
    for(int i=1;i<n;i++){
        if(nums[i]%2){//odd
            if(even!=-1 && last==0) {l1++;last=1;}
            if(odd!=-1) l2++;
            odd=i;
        }
        else{
            if(odd!=-1 && last==1) {l1++;last=0;}
            if(even!=-1) l3++;
            even=i;
        }
    }
    return max(l1,max(l2,l3));
}
int main(){
    cout<<solve({2,39,23})<<endl;
    return 0;
}