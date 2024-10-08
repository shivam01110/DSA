#include <bits/stdc++.h>
using namespace std;

void buildSegTree(int i,int l,int r,vector<int>& segTree,vector<int>& arr){
    if(l==r){
        segTree[i]=arr[i];
        return ;
    }
    int mid=(l+r)/2;
    buildSegTree(i,l,mid,segTree,arr);  //left
    buildSegTree(i,mid+1,r,segTree,arr);    //right
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

void updateSegTree(int ind,int val,int i,int l,int r,vector<int>& segTree){
    if(l==r){
        segTree[i]=val;
        return;
    }
    int mid=(l+r)/2;
    if(ind<=mid){
        updateSegTree(ind,val,i,l,mid,segTree);  //left
    }
    else{
        updateSegTree(ind,val,i,mid+1,r,segTree);    //right
    }
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

int Query(int start,int end,int ind,int l,int r,vector<int>& segTree){
    if(end<l || r<start){//out of Bound
        return 0;
    }
    else if(start<=l && r<=end){
        return segTree[ind];
    }
    else{
        int mid=(l+r)/2;
        return Query(start,end,2*ind+1,l,mid,segTree)+Query(start,end,2*ind+2,mid+1,r,segTree);
    }
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //size of segment Tree=n(leaf nodes)+n-1(non-leaf nodes)=2n-1
    // vector<int> segTree(2*n-1,0);

}