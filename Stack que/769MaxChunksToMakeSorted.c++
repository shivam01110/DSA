#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n=arr.size(),chunks=0;
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++){
        sum1+=i;
        sum2+=arr[i];
        if(sum1==sum2){
            chunks++;
            sum2=0;
            sum1=0;
        }
    }
    return chunks;
}