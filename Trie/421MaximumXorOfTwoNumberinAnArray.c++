#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* link[2];
    bool containBit(int bit){
        return link[bit]!=nullptr;
    }
    void put(int bit,Node* node){
        link[bit]=node;
    }
    Node* get(int bit){
        return link[bit];
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
            if(!node->containBit(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int maxXOr(int num){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int req=1-bit;
            if(node->containBit(req)){
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int MaxXorFornum=trie.maxXOr(nums[i]);
            cout<<MaxXorFornum<<endl;
            maxi=max(maxi,MaxXorFornum);
        }
        return maxi;
    }
};