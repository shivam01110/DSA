#include <bits/stdc++.h>
using namespace std;

int FindTheMaximumZero(vector<int>& arr){
    int cnt=0,mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=mini && arr[i]>0){
            cnt++;
            mini=arr[i];
        }
    }
    return cnt;
}

int main(){
    vector<int> arr={3,2,4,4,2};
    cout<<FindTheMaximumZero(arr)<<endl;
    return 0;
}