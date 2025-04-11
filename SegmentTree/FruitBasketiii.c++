#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void BuildSegTree(int i,int l,int r,vector<int>& segTree,vector<int>& basket){
        if(l==r){
            segTree[i]=basket[l];
            return;
        }
        int mid=l+(r-l)/2;
        BuildSegTree(2*i+1,l,mid,segTree,basket);
        BuildSegTree(2*i+2,mid+1,r,segTree,basket);
        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
    }

    void update(int i,int l,int r,int req,vector<int>& segTree,int& unplaced){
        if(segTree[i]<req) return;
        if(l==r){
            segTree[i]=0;
            unplaced-=1;
            return;
        }
        int mid=l+(r-l)/2;
        if(req<=segTree[2*i+1]){
            update(2*i+1,l,mid,req,segTree,unplaced);
        }else update(2*i+2,mid+1,r,req,segTree,unplaced);
        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // vector<int> fruit={6,4,8},basket={5,8,7};
        int n=fruits.size(),unplaced=n;
        vector<int> segTree(4*n,0);
        BuildSegTree(0,0,n-1,segTree,baskets);
        for(int i=0;i<n;i++){
            update(0,0,n-1,fruits[i],segTree,unplaced);
        }
        return unplaced;
    }
};