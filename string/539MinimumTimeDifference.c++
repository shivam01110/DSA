#include <bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string>& timePoints) {
    vector<int> tp;
    int l=timePoints.size();
    for(auto t:timePoints){
        int timeInMin=((t[0]-'0')*10+(t[1]-'0'))*60+(t[3]-'0')*10+(t[4]-'0');
        tp.push_back(timeInMin);
    }
    sort(tp.begin(),tp.end());
    int minDiff=INT_MAX;
    for(int i=0;i<l;i++){
        int d1=abs(tp[i]-tp[(l+i-1)%l]);    //difference b/w curr and prev timepoints (in circular fashion)
        if(d1>720) d1=1440-d1;  //to handle circular nature of clock
        int d2=abs(tp[i]-tp[(i+1)%l]);      //difference b/w curr and next timepoints(in circular fashion)
        if(d2>720) d2=1440-d2;  //to handle circular nature of clock
        minDiff=min(minDiff,min(d1,d2));
    }
    return minDiff;
}