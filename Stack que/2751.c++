#include <bits/stdc++.h>
using namespace std;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    vector<pair<int,pair<int,char>>> phd;   //phd-->position health direction
    for(int i=0;i<positions.size();i++){
        phd.push_back({positions[i],{healths[i],directions[i]}});
    }
    sort(phd.begin(),phd.end());
    stack<pair<int,pair<int,char>>> s;  //{pos,{health,direction}}
    int i=0,l=phd.size();
    while(i<l){
        if(!s.empty() && s.top().second.second=='R' && phd[i].second.second=='L'){
            if(s.top().second.first<phd[i].second.first){
                s.pop();
                phd[i].second.first--;
            }
            else if(s.top().second.first>phd[i].second.first){
                s.top().second.first--;
                i++;
            }
            else{
                s.pop();
                i++;
            }
        }
        else{
            s.push({phd[i].first,{phd[i].second.first,phd[i].second.second}});
            i++;
        }
    }
    unordered_map<int,int> m;
    while(!s.empty()){
        m[s.top().first]=s.top().second.first;
        s.pop();
    }
    vector<int> res;
    for(int j=0;j<positions.size();j++){
        if(m.find(positions[j])!=m.end()){
            res.push_back(m[positions[j]]);
        }
    }
    return res;
}
