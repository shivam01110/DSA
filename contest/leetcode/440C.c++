#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        priority_queue<int,vector<int>,greater<int>> pq;   //min heap for encounter fruits
        unordered_map<int,int> m;   //frequency of each element of s 
        set<int> s;
        for(int i=0;i<n;i++){
            pq.push(fruits[i]);
            s.insert(baskets[i]);
            m[baskets[i]]+=1;
            while(!pq.empty() && s.lower_bound(pq.top())!=s.end()){
                int fruit=pq.top();
                int basket=*s.lower_bound(fruit);
                m[basket]-=1;
                if(m[basket]==0){
                    m.erase(basket);
                    s.erase(basket);
                }
                pq.pop();   //remove the top fruit if it can be put in basket
            }
        }
        return pq.size();
    }
};



int main(){
    // unordered_map<int,int> m;
    // m[1]+=1;
    // m[2]+=2;
    // for(auto it:m){
    //     cout<<it.first<<"---->"<<it.second<<endl;
    // }
    cout<<char('0'+900000000000)<<endl;
    return 0;
}