#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int solve(vector<int>& arr){
    vector<int> first(3,1),sec(3,1),temp(3,0);
    for(int i=2;i<=arr[6];i++){
        temp[0]=(arr[0]*sec[0]+arr[1]*first[1])%mod;
        temp[1]=(arr[2]*sec[1]+arr[3]*first[2])%mod;
        temp[3]=(arr[4]*sec[2]+arr[5]*first[0])%mod;
        first=sec;
        sec=temp;
    }
    return sec[0];
}

int main(){
    vector<int> arr={5,6,3,7,1,2,5};
    cout<<solve(arr)<<endl;
    return 0;
}