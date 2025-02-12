#include <bits/stdc++.h>
using namespace std;


// For the bitwise AND to be greater than zero, at least one bit should be 1 for every number in the combination
int largestCombination(vector<int>& candidates) {
    vector<int> freq(25,0);
    for(auto c:candidates){
        int p=0;
        while(c){
            if(c&1) freq[p]++;
            p++;
            c>>=1;
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<25;i++){
        maxi=max(maxi,freq[i]);
    }
    return maxi;
}