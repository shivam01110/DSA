#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool CustomCamparator(vector<int>& a,vector<int>& b){
        if(a[1]!=b[1]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    static bool CustomCamparator2(pair<string,int>& a,pair<string,int>& b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second<b.second;
    }

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),l=queries.size();
        vector<pair<string,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<vector<int>>que(l);
        for(int i=0;i<l;i++){
            que[i]={queries[i][0],queries[i][1],i};
        }
        sort(que.begin(),que.end(),CustomCamparator);
        vector<int> res(l,0);
        for(auto q:que){
            int x=q[1];
            int ind=q[2];
            int pos=q[0];
            for(int i=0;i<n;i++){
                arr[i].first=arr[i].first.substr(arr[i].first.length()-x);
            }
            sort(arr.begin(),arr.end(),CustomCamparator2);
            res[ind]=arr[pos-1].second;
        }
        return res;
    }
};

int main(){
    string str="shivam";
    str=str.substr(3);
    cout<<str<<endl;
    return 0;
}