#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<'{'<<arr[i][0]<<','<<arr[i][1]<<'}';
        if(i!=arr.size()-1)cout<<',';
    }
    cout<<endl;
}

struct comparator{
    bool operator()(const vector<int>& a,const vector<int>& b) const{
        if(a[0]==b[0]){
            return a[1]<b[1];   //first elements are equal,sort by the second element in ascending order
        }
        return a[0]>b[0];   //sort by the first element in descending order
    }
};


void reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),comparator());
    print(people);
    int n=people.size();
    vector<vector<int>> SortedPeople;
    for(int i=0;i<n;i++){
        int ind=people[i][1];
        SortedPeople.push_back(people[i]);
        int lastpos=SortedPeople.size()-1;
        while(ind!=lastpos){
            swap(SortedPeople[lastpos],SortedPeople[lastpos-1]);
            lastpos--;
        }
    }
    print(SortedPeople);
}

int main(){
    vector<vector<int>> people={{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    reconstructQueue(people);
    return 0;
}