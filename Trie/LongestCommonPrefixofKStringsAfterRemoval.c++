#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* link[26];
    int cnt=0;  //the number of the words store in the node
    int dpt=0;  //depth refers to the depth of the current node
    set<int> s; //to store the index of the words store in the node
    bool containkey(char ch){
        return link[ch-'a']!=nullptr;
    }
    Node* getNext(char ch){
        return link[ch-'a'];
    }
    void put(char ch,Node* node){
        link[ch-'a']=node;
    }
    void increaseCnt(){
        cnt++;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string word,int i){
        Node* node=root;
        int d=1;
        for(char ch:word){
            if(!node->containkey(ch)){
                node->put(ch,new Node());
            }
            node=node->getNext(ch);
            node->increaseCnt();
            node->dpt=d;
            node->s.insert(i);
            d++;
        }
    }

    void MaxPrefixLen(int& maxi,vector<int>& res,Node* node,int k){
        if(!node || node->cnt<k) return;
        if(node->cnt>k){
            maxi=max(node->dpt,maxi);   //maximize the depth(length of longest common prefix (cnt>k) string)
            for(int i=0;i<26;i++){
                if(node->link[i] && node->link[i]->cnt>=k){
                    MaxPrefixLen(maxi,res,node->link[i],k);
                }
            }
        }else{
            //find the node with cnt==k and have highest depth
            bool flag=0;
            for(int i=0;i<26;i++){
                if(node->link[i] && node->link[i]->cnt==k){
                    MaxPrefixLen(maxi,res,node->link[i],k);
                    flag=1;
                }
            }
            if(!flag){
                //update the depth (length of longest common prefix (cnt==k) string) for all the value of i except those which are in node->s
                for(int i=0;i<res.size();i++){
                    if(node->s.find(i)==node->s.end()){
                        res[i]=max(res[i],node->dpt);
                    }
                }
            }
        }
    }

    void solve(vector<int>& res,int& maxi,int k){
        for(int i=0;i<26;i++){
            if(root->link[i]){
                MaxPrefixLen(maxi,res,root->link[i],k);
            }
        }
    }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie t;
        int l=words.size();
        vector<int> res(l,0);
        for(int i=0;i<l;i++){
            t.insert(words[i],i);
        }
        int maxi=0;
        t.solve(res,maxi,k);
        for(int i=0;i<l;i++){
            res[i]=max(maxi,res[i]);
        }
        return res;
    }
};