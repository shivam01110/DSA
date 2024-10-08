#include <bits/stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int>& arr) {
    int l=arr.size();
    vector<int> small(l+1,INT_MAX);   //store the smallest element on the right from the current element
    for(int i=l-1;i>=0;i--){
        small[i]=min(small[i+1],arr[i]);
    }
    int chunks=0;
    int maxi=INT_MIN;
    for(int i=0;i<l;i++){
        maxi=max(maxi,arr[i]);
        if(maxi<=small[i+1]){       //largest element from the left part should be less than or equal to smallest element from the right part of the array
            chunks++;
            maxi=INT_MIN;
        }
    }
    return chunks;
}