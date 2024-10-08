#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree {
public:
    vector<pair<int,int>> booking;
    int k=INT_MIN;
    MyCalendarThree(){

    }
    
    int book(int start, int end) {
        set<pair<int,int>> s;
        booking.push_back({start,end});
        for(int i=0;i<booking.size();i++){
            if((start<=booking[i].first && booking[i].first <end) || (booking[i].first<=start && start<booking[i].second)){
                pair<int,int> intersection={max(start,booking[i].first),min(end,booking[i].second)};
                if(s.find(intersection)==s.end()){
                    int cnt=0;
                    for(int j=0;i<booking.size();j++){
                        if(booking[j].first<start && end <booking[j].second){
                            cnt++;
                        }
                    }
                    k=max(k,cnt);
                }
            }
        }
        return k;
    }
};