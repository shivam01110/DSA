#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* curr=head;
    while(curr->next){
        int x=__gcd(curr->val,curr->next->val);
        ListNode* gcd=new ListNode(x,curr->next);
        curr->next=gcd;
        curr=gcd->next;
    }
    return head;
}