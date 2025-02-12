#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a,vector<int> b) {
    int n=a.size();
    vector<int> maxb(n,INT_MIN);
    maxb[n-1]=b[n-1];
    for(int i=n-2;i>=0;i--){
        maxb[i]=max(maxb[i+1],b[i]);
    }
    vector<int> maxa(n,INT_MIN);
    maxa[0]=a[0];
    for(int i=1;i<n;i++){
        maxa[i]=max(maxa[i-1],a[i]);
    }
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        res=min(res,max(maxa[i],maxb[i]));
    }
    return res;
}


int main(){
    vector<int> a={3,4,6};
    vector<int> b={6,5,4};
    cout<<solution(a,b)<<endl;
    return 0;
}