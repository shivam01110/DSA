#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int qsize=queries.size(),n=nums.size(),j=0,take=0;
        //sort ascending order->queries[i][0]  && descending order-> queries[i][1]
        sort(queries.begin(),queries.end(),[](const vector<int>&a,const vector<int>& b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        priority_queue<int> candidate;      //store the end range in max heap
        priority_queue<int,vector<int>,greater<int>> choosen;   //store the end range in min heap
        for(int i=0;i<n;i++){
            //put all the queries whose start range is equal to i
            while(j<qsize && queries[j][0]==i){
                candidate.push(queries[j][1]);
                j++;
            }
            // while choosen size is less than nums[i] then push all the candidate whose value is greater or equal to current index i
            while(choosen.size()<nums[i] && !candidate.empty() && candidate.top()>=i){
                take++;
                choosen.push(candidate.top());
                candidate.pop();
            }
            if(choosen.size()<nums[i]) return -1;   //if nums[i] cannot reduce to 0 return -1
            //remove all the queries from the choosen whose end is less than or equal to i
            while(!choosen.empty() && choosen.top()<=i){
                choosen.pop();
            }
        }
        return qsize-take;
    }
};