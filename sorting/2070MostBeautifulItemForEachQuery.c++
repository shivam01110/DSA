#include <bits/stdc++.h>
using namespace std;

int upperbound(vector<vector<int>>& items,int q){
    int l=0,h=items.size()-1;
    while(l<h){
        int mid=l+(h-l)/2;
        int val=items[mid][0];
        if(val<=q) l=mid+1;
        else{h=mid;}
    }
    return l;
}

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(),items.end());
    int n=items.size(),maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,items[i][1]);
        items[i][1]=maxi;
    }
    int l=queries.size();
    for(int i=0;i<l;i++){
        if(queries[i]<items[i][0]) queries[i]=0;
        else if(queries[i]>=items[n-1][0]) queries[i]=items[n-1][1];
        else{
            int ind=upperbound(items,queries[i]);
            queries[i]=items[ind-1][1];
        }
    }
    return queries;
}