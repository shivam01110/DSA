#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> res(m,vector<int>(n,-1));
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    int d=0,r=0,c=0;
    while (head){
        res[r][c]=head->val;
        head=head->next;
        int nr=r+dir[d][0],nc=c+dir[d][1];
        if(0>=nr || nr>m || 0>=nc || nc>n || (0<=nr && nr<m && 0<=nc && nc<n && res[nr][nc]!=-1)){
            d=(d+1)%4;
            nr=r+dir[d][0];
            nc=c+dir[d][1];
        }
        r=nr,c=nc;
    }
    return res;
}