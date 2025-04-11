#include <bits/stdc++.h>
using namespace std;

const int mod=1000;

class Solution{
public:
    void BuildSegTree(int ind,int l,int r,vector<int>& segTree){
        if(l==r){
            segTree[ind]=1;
            return; 
        }
        int mid=l+(r-l)/2;
        BuildSegTree(2*ind+1,l,mid,segTree);
        BuildSegTree(2*ind+2,mid+1,r,segTree);
        segTree[ind]=segTree[2*ind+1]+segTree[2*ind+2];
    }
    void update(int ind, int l, int r, int& req, int h, int pos, vector<int>& segTree, vector<vector<int>>& res) {
        if (l == r) {
            segTree[ind] = 0;  // Mark position as occupied
            res[l] = {h, pos};
            return;
        }
        int mid = l + (r - l) / 2;
        if (req <= segTree[2 * ind + 1]) 
            update(2 * ind + 1, l, mid, req, h, pos, segTree, res);  // Go left
        else {
            req -= segTree[2 * ind + 1];  // Skip left subtree elements
            update(2 * ind + 2, mid + 1, r, req, h, pos, segTree, res);  // Go right
        }
        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];  // Update parent node
    }   
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>> res(n,vector<int>(2,0));
        vector<int> segTree(4*n);
        BuildSegTree(0,0,n-1,segTree);
        sort(people.begin(),people.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        for(int i=0;i<n;i++){
            int pos=people[i][1]+1;
            int h=people[i][0];
            update(0,0,n-1,pos,h,pos-1,segTree,res);
        }
        return res;
    }
};
int main(){

}