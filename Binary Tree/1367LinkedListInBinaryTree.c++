#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(): val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

bool check(TreeNode* root,ListNode* head){
    if(head==nullptr) return true;  //linked list is found
    if(root==nullptr) return false; //we have reached to end of the current branch Binary Tree ,Linked list cannot be traversed further
    if(head->val!=root->val) return false;
    return check(root->left,head->next) || check(root->right,head->next);
}

bool isSubPath(ListNode* head,TreeNode* root){
    if(root==nullptr) return false;
    return check(root,head) || isSubPath(head,root->left) ||isSubPath(head,root->right);
}
