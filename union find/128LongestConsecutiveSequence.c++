#include <bits/stdc++.h>
using namespace std;

//find the ultimate parent of node
int findpar(unordered_map<int,int>& m,int node){
    while(m[node]!=node){
        node=m[node];
    }
    return node;
}


int longestConsecutive(vector<int>& nums){
    unordered_map<int,int> parentsize,node;
    int maxi=0;
    for(int i=0;i<nums.size();i++){
        if(node.count(nums[i])) continue;
        int par=nums[i];
        int tot=1;
        if(node.count(nums[i]-1)) {int nodepar=findpar(node,nums[i]-1);tot+=parentsize[nodepar];par=min(par,nodepar);}
        if(node.count(nums[i]+1)) {int nodepar=findpar(node,nums[i]+1);tot+=parentsize[nodepar];par=min(par,nodepar);}
        if(node.count(nums[i]-1)) node[nums[i]-1]=par;
        if(node.count(nums[i]+1)) node[nums[i]+1]=par;
        node[nums[i]]=par;
        parentsize[par]=tot;
        maxi=max(maxi,tot);
    }
    return maxi;
}