#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* link[26];
    bool flag=false;

    bool containKey(char ch){
        return link[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        link[ch-'a']=node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    bool setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
      root=new Node();  
    }
    int insert(string w){
        Node* node=root;
        int cnt=0;
        for(char c:w){
            //if substring doesn't exist in the tree then add 1
            if(!node->containKey(c)){
                node->put(c,new Node());
                cnt++;
            }
            node=node->get(c);
            node->setEnd();
        }
        node->setEnd();
        return cnt++;
    }
};

int DistinctSubstr(string str){
    Trie t;
    int l=str.length(),res=0;
    for(int i=0;i<l;i++){
        string s=str.substr(i,l-i);
        res+=t.insert(s);
    }
    return res+1;   //add 1 for empty substring
}

int main(){
    string s="shivam";
    cout<<DistinctSubstr(s)<<endl;
    return 0;
}