#include <bits/stdc++.h>
using namespace std;

#define ll long long

int outliers(vector<int> arr){
    int l=arr.size();
    ll sum=0;
    int res=-1;
    sort(arr.begin(),arr.end());
    for(auto n:arr) sum+=n;
    int outlier=INT_MIN;
    for(int i=0;i<l;i++){
        //every number can be a possible candidate for special num
        int specialSum=sum-arr[i];  //sum of remaining num (i.e sum-outlier)
        if(specialSum%2) continue;  //since all integer so if specialSum is odd then specialSum%2 will be float so continue to next iteration
        int specialNum=(specialSum)/2;  //since remaining sum=special number(n-2 numbers)+number equal sum of special number(specialNum)
        int present=binary_search(arr.begin(),arr.end(),specialNum); //check whether specialNum is present in the arr 
        //outliers and the specialSum should have different index
        if(arr[i]!=specialNum && present) outlier=max(outlier,arr[i]);
        if(present && arr[i]==specialNum && (arr[(i+1)%l]==specialNum || arr[(i-1+l)%l]==specialNum)) outlier=max(outlier,arr[i]);
    }
    return outlier;
}

int main(){
    vector<int> arr={2,2,4,2};
    vector<int> arr2={4,1,2,1,10,3};
    cout<<outliers(arr)<<endl;
    cout<<outliers(arr2)<<endl;
    return 0;
}