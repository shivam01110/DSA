#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void print(vector<vector<int>>& input){
        for(vector<int> i:input){
            cout<<i[0]<<"<-->"<<i[1]<<"-->"<<i[2]<<endl;
        }
    }
    vector<vector<int>> SolvePaint(vector<vector<int>> p){
        map<int,int> m; //point->cost
        for(vector<int> v:p){
            m[v[0]]+=v[2];
            m[v[1]]-=v[2];
        }
        vector<vector<int>> res;
        auto it=m.begin();
        int tot=0,start=it->first,end=-1,cost=it->second;
        it++;
        while(it!=m.end()){
            end=it->first;
            res.push_back({start,end,cost});
            cost+=it->second;
            start=it->first;
            it++;
        }
        return res;
    }
};

int main(){
    Solution sol;   //creating an object for the class Solution
    vector<vector<int>> input={{10,15,9},{0,9,6},{7,12,8},{7,10,11}};
    vector<vector<int>> output=sol.SolvePaint(input);
    sol.print(output);
    return 0;
}