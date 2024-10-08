#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> countingSort(vector<int>& arr){
    unordered_map<int,int> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    int i=0;

    int minEle=*min_element(arr.begin(),arr.end());
    int maxEle=*max_element(arr.begin(),arr.end());

    for(int num=minEle;num<=maxEle;num++){
        if(m[num]){
            while (m[num]){
                arr[i]=num;
                m[num]--;
                i++;
            }
        }
    }
    return arr;
}

int main(){
    vector<int> arr={5,3,2,1};
    countingSort(arr);
    print(arr);
    return 0;
}