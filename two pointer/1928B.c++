// 2pointer + sorting

//solution
// Suppose we already know the permutation that needs to be added. 
// Let's consider the elements that will become equal after the addition. 
// Notice that among them there cannot be equal elements, because among the numbers we are adding, there are no duplicates. 
// Thus, only a set of numbers among which there are no equal ones, and the difference between the maximum and minimum does not exceed n−1,
//  can become equal. It is easy to see that any set of numbers satisfying these conditions can be equalized, 
// and any set of numbers that became equal after adding the permutation satisfies these constraints.
// So let's sort the array, remove the equal elements from it. 
// After that, we can use two pointers to find the maximum length subarray where the difference between the maximum and minimum does not exceed n−1.
// The answer will be the length of such a subarrayThe complexity of the solution is O(nlogn)
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    set<int> s;
    int a,res=INT_MIN;
    for(int i=0;i<n;i++) cin>>a,s.insert(a);
    vector<int> arr(s.begin(),s.end());
    int p1=0,p2=0;
    for(;p2<arr.size();p2++){
        if(arr[p2]-arr[p1]>n-1) p1++;
        res=max(res,p2-p1+1);
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}