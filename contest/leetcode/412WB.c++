#include <bits/stdc++.h>
using namespace std;


bool valid(int n1,int n2){
    if(n1==n2) return true;
    int mismatch=0;
    int m1=-1,m2=-1,m3=-1,m4=-1;
    while(n1 || n2){
        if(n2%10!=n1%10){
            mismatch++;
            if(mismatch==1){
                m1=n1%10;
                m3=n2%10;
            }
            else{
                m2=n1%10;
                m4=n2%10;
            }
        }
        if(mismatch>3) return false;
        n1/=10;
        n2/=10;
    }
    if(mismatch==2 && m1==m4 && m3==m2) return true;
    return false;
}

int countPairs(vector<int>& nums) {
    int n=nums.size();
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(valid(nums[i],nums[j])){
                c++;
            }
        }
    }
    return c;
}