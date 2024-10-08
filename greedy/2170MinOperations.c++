#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums){
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i%2) m1[nums[i]]++;  //odd
        else m2[nums[i]]++;     //even
    }
    priority_queue<pair<int,int>> pq1;
    priority_queue<pair<int,int>> pq2;
    for(auto it=m1.begin();it!=m1.end();it++){
        pq1.push({it->second,it->first});
    }
    for(auto it=m2.begin();it!=m2.end();it++){
        pq2.push({it->second,it->first});
    }

}