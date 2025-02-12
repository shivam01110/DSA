#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* link[26];
    int endwith=0;
    int cntPrefix=0;

    bool containsKey(char ch){
        return link[ch-'a']!=nullptr;
    }
    Node* get(char ch) {
        return link[ch-'a'];
    }
    void put(char ch,Node* node){
        link[ch-'a']=node;
    }
    void increaseEndWith(){
        endwith++;
    }
    void increaseCntPrefix(){
        cntPrefix++;
    }
    void DecreaseEndWith(){
        endwith--;
    }
    void DecreaseCntPrefix(){
        cntPrefix--;
    }
    
};

class Trie{
private: Node* root;
public:
    Trie(){
        root=new Node();//create new object
    }
    void insert(string word){
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }
            node=node->get(c);
            node->increaseCntPrefix();
        }
        node->increaseEndWith();
    }
    int cntWordEqualTo(string word){
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c)){
                return 0;
            }
            node=node->get(c);
        }
        return node->endwith;
    }
    int CntStartWith(string word){
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c)){
                return 0;
            }
            node=node->get(c);
        }
        return node->cntPrefix;
    }
    //assuming word exist before deleting
    void erase(string word){
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c)) return; 
            node=node->get(c);
            node->DecreaseCntPrefix();
        }
        node->DecreaseEndWith();
    }
};