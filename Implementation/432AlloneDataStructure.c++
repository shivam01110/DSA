#include <bits/stdc++.h>
using namespace std;

class AllOne {
public:
    struct Node{
        int freq;
        list<string> s;
        Node* next;
        Node* prev;
        Node(int f){
            freq=f;
            prev=nullptr;
            next=nullptr;
        }
        
    };
    
    void addnode(Node* pos,int c){
        Node* newnode=new Node(c);
        Node* posnext=pos->next;
        newnode->next=pos->next;
        newnode->prev=pos;
        pos->next=newnode;
        posnext->prev=newnode;
    }
    void removeNode(Node* adr){
        Node* adrprev=adr->prev;
        Node* adrnext=adr->next;
        adrprev->next=adrnext;
        adrnext->prev=adrprev;
        delete adr;
    }
    unordered_map<string,Node*> m;   //string-->freq
    Node* head;
    Node* tail;
    AllOne(){
        head=new Node(0);
        tail=new Node(0);
        head->next=tail;
        tail->prev=head;
    }
    
    void inc(string key) {
        if(!m.count(key)){
            if(head->next==tail || head->next->freq!=1){
                addnode(head,1);
            }
            m[key]=head->next;
            head->next->s.push_back(key);
        }
        else{
            Node* adr=m[key];
            int cnt=adr->freq;
            if(adr->next==tail || adr->next->freq!=cnt+1){
                addnode(adr,cnt+1);
            }
            m[key]=adr->next;
            adr->next->s.push_back(key);
            adr->s.remove(key);
            if(adr->s.empty()) removeNode(adr);
        }
    }
    
    void dec(string key) {
        Node* adr=m[key];
        int cnt=adr->freq;
        if(cnt==1){
            m.erase(key);
        }
        else if(adr->prev==head || adr->prev->freq!=cnt-1){
            addnode(adr->prev,cnt-1);
        }
        if(cnt!=1){
            m[key]=adr->prev;
            adr->prev->s.push_back(key);
        }
        adr->s.remove(key);
        if(adr->s.empty()) removeNode(adr);
        
    }
    
    string getMaxKey() {
        if(tail->prev==head) return "";
        string res= *(tail->prev->s.begin());
        return res;
    }
    
    string getMinKey() {
        if(head->next==tail) return "";
        string res= *(head->next->s.begin());
        return res;
    }
};