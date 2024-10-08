#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    set<pair<int,int>> s;
    set<pair<int,int>> intersection;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it=intersection.begin();it!=intersection.end();it++){
            int is=it->first;
            int ie=it->second;
            if((is<=start && start<ie) || (start<=is && is< end)) return false;
        }
        for(auto i=s.begin();i!=s.end();i++){
            int ss=i->first;
            int se=i->second;
            if((ss<=start && start<se) || (start<=ss && ss< end)){
                int rs=max(start,ss);
                int re=min(se,end);
                intersection.insert({rs,re});
            }
        }
        s.insert({start,end});
        return true;
    }
};