#include <bits/stdc++.h>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* curr=dummy->next;
        ListNode* prev=dummy;
        while(curr){
            bool exist=binary_search(nums.begin(),nums.end(),curr->val);
            if(exist){
                prev->next=curr->next;
            }
            else{
                prev=prev->next;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};