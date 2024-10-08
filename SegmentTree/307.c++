#include <bits/stdc++.h>
using namespace std;

class NumArray {
    int n;
    vector<int> segTree;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        int len=4*n;    //length of segment Tree
        segTree.resize(len,0);
        buildSegTree(0,0,n-1,nums,segTree);
    }
    void buildSegTree(int i,int l,int r,vector<int>& nums,vector<int>& segTree){
        if(l==r){
            segTree[i]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        buildSegTree(2*i+1,l,mid,nums,segTree);
        buildSegTree(2*i+2,mid+1,r,nums,segTree);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    
    void updateSegTree(int ind,int val,int i,int l,int r,vector<int>& segTree){
        if(l==r){
            segTree[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(ind<=mid){
            updateSegTree(ind,val,2*i+1,l,mid,segTree);
        }
        else{
            updateSegTree(ind,val,2*i+2,mid+1,r,segTree);
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    void update(int index, int val) {
        int i=0,l=0,r=n-1;
        updateSegTree(index,val,i,l,r,segTree);
    }
    
    int solveRange(int start, int end,int i,int l,int r,vector<int>&segTree) {
        if(end<l || r<start) return 0; //no overlapping
        else if(l<=start && end<=r){
            return segTree[i];  //pure overlapping
        }
        else{//partial overlapping;
            int mid=(l+r)/2;
            return solveRange(start,end,2*i+1,l,mid,segTree)+solveRange(start,end,2*i+2,mid+1,r,segTree);
        }
    }

    int sumRange(int left, int right) {
        int i=0,l=0,r=n-1;
        solveRange(left,right,i,l,r,segTree);
    }
};