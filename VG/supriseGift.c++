#include <bits/stdc++.h>
using namespace std;

long getMaxValue(vector<long> a,vector<long> b,vector<long> c){
    int n=a.size();
    int mod=1e9+7;
    vector<long> sum(n,0);
    for(int i=0;i<a.size();i++){
        sum[i]=a[i]+b[i]+c[i];
    }
    sort(sum.begin(),sum.end());
    long tot=0;
    for(int i=0;i<n;i++){
        tot=(tot+(sum[i]*(i+1))%mod)%mod;
    }
    return tot;
}

int main(){
    vector<long> a={3,2,1};
    vector<long> b={4,10,1};
    vector<long> c={1,10,2};
    cout<<getMaxValue(a,b,c)<<endl;
    return 0;
}