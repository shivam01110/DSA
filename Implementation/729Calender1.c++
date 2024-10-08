#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it=s.begin();it!=s.end();it++){
            int s=it->first;
            int e=it->second;
            if((s<=start && start<e) ||(start<=s && s<end)) return 0; 
        }
        s.insert({start,end});
        return 1;
    }
};