#include <bits/stdc++.h>
using namespace std;

#define ll long long
//determine the height which can be remove in time t by ith worker
ll height(ll timeLimit,ll time,ll h){
    ll low=1,high=h;
    timeLimit=timeLimit/time;
    while(low<=high){
        ll mid=low+(high-low)/2;
        ll cal=mid*(mid+1)/2;
        if(cal>timeLimit){
            high=mid-1;
        }
        else if(cal<timeLimit){
            low=mid+1;
        }
        else return mid;
    }
    return high;
}

bool possible(vector<int>& arr,ll timeLimit,ll h){
    ll temp=h;
    for(auto wt:arr){
        temp=temp-height(timeLimit,wt,h);
        if(temp<=0) return true;
    }
    return false;
}

long long minNumberOfSeconds(int height, vector<int>& workerTimes) {
    sort(workerTimes.begin(),workerTimes.end());
    ll low=1;
    ll high=((ll)(height)*(ll)(height+1)/2)*workerTimes.back();
    while(low<high){
        ll mid=low+(high-low)/2;
        if(possible(workerTimes,mid,height)){
            high=mid;
        }
        else low=mid+1;
    }
    return low;
}