#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int CntSetBit(int num){
        int cnt=0;
        while(num){
            if(num&1) cnt++;
            num=num>>1;
        }
    }
    bool solution(vector<int> arr){
        int n=arr.size();
        vector<int> setBit(n,0);
        for(int i=0;i<n;i++){
            setBit[i]=CntSetBit(arr[i]);
        }
        int prevMax=INT_MIN,prevMin=INT_MAX;
        int currMax=INT_MIN,currMin=INT_MAX;
        int l=0,r=0;
        while(r<n){
            while(r<n && setBit[l]==setBit[r]){
                currMax=max(currMax,arr[r]);
                currMin=min(currMin,arr[r]);
                r++;
            }
            if(currMin<prevMax) return false;
            l=r;
            prevMax=currMax,prevMin=currMin;
            currMax=INT_MIN,currMin=INT_MAX;
        }
        return true;
    }
};

int main(){

}