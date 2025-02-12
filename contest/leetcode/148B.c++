#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define ll long long
class Solution {  
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        ll d1=0,d2=0;
        for(int i=0;i<arr.size();i++){
            d1+=abs(arr[i]-brr[i]);
        }
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        for(int i=0;i<arr.size();i++){
            d2+=abs(arr[i]-brr[i]);
        }
        d2+=k;
        return min(d1,d2);
    }
};