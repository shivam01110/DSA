#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    set<int> s;
    for(int ele:arr){
        s.insert(ele);
    }
    vector<int> sortedArr(s.begin(),s.end());
    vector<int> res;
    for(int i=0;i<arr.size();i++){
        int pos=lower_bound(sortedArr.begin(),sortedArr.end(),arr[i])-sortedArr.begin()+1;
        res.push_back(pos);
    }
    return res;
}