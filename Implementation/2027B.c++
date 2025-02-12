#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<int> largeOnRight(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]) largeOnRight[i]++;
        }
    }
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        res=min(res,i+largeOnRight[i]);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}