#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(nullptr){}
};



vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len=0;
    ListNode* curr=head;
    while(curr){
        curr=curr->next;
        len++;
    }
    int extra=len%k;
    int l=len/k;
    vector<ListNode*> res(k,nullptr);
    for(int i=0;i<k && head;i++){
        curr=head;
        res[i]=head;
        if(i<extra){
            for(int j=1;j<=l&& curr;j++){
                curr=curr->next;
            }
            if(curr){head=curr->next;
            curr->next=nullptr;}
        }
        else{
            for(int j=1;j<l && curr;j++){
                curr=curr->next;
            }
            if(curr){head=curr->next;
            curr->next=nullptr;}
        }
    }    
    return res;    
}