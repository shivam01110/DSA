#include <bits/stdc++.h>
using namespace std;
int recurrsion(int i,vector<int> arr){
    if(arr.size()<1 || i==arr.size()-1) return 0;
    int maxi=INT_MIN;
    maxi=max(maxi,recurrsion(i+1,arr));
    if(arr[i]==i+1){
        arr.erase(arr.begin()+i);
        arr.erase(arr.begin()+i);
        maxi=max(maxi,1+recurrsion(0,arr));
    }
    return maxi;
}
string vecToStr(int i,vector<int>& vec) {
    string result=to_string(i)+".";
    for (int num : vec) {
        result += to_string(num) + ",";
    }
    return result;
}
int memo(int i,vector<int> arr,unordered_map<string,int>& m){
    if(arr.size()<1 || i==arr.size()-1) return 0;
    string key = vecToStr(i,arr);
    if(m.find(key)!=m.end()) return m[key];
    int maxi=INT_MIN;
    maxi=max(maxi,memo(i+1,arr,m));
    if(arr[i]==i+1){
        arr.erase(arr.begin()+i);
        arr.erase(arr.begin()+i);
        maxi=max(maxi,1+memo(0,arr,m));
    }
    return m[key]=maxi;
}

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    unordered_map<string,int> m;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<memo(0,arr,m)<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}