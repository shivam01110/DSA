#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        int minheight=INT_MAX;
        ll sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<maximumHeight.size();i++){
            if(m[maximumHeight[i]]==0){
                minheight=min(minheight,maximumHeight[i]);
            }
            else{
                minheight--;
                if(minheight==0) return -1;
            }
            m[minheight]=1;
            sum+=minheight;
        }
        return sum;
    }
};