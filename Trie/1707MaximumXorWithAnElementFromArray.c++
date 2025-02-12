#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* link[2];
    bool containKey(int key){
        return link[key]!=nullptr;
    }
    void put(int key,Node* node){
        link[key]=node;
    }
    Node* get(int key){
        return link[key];
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int MaxXor(int num){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int req=1-bit;
            if(node->containKey(req)){
                maxi=maxi|(1<<i);
                node=node->get(req);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxi;
    }    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        sort(nums.begin(),nums.end());
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(),q.end());
        int n=q.size();
        vector<int> res(n,-1);
        int l=0;
        for(int i=0;i<n;i++){
            int m=q[i][0],x=q[i][1],ind=q[i][2];
            while(l<nums.size() && nums[l]<=m){
                t.insert(nums[l]);
                l++;
            }
            // Check if the Trie is empty for the current query
            if(l)res[ind]=t.MaxXor(x);
        }
        return res;
    }
};