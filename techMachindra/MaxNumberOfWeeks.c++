#include <bits/stdc++.h>
using namespace std;

long long numberOfWeeks(vector<int>& m) {
    sort(m.begin(),m.end());
    int n=m.size();
    long long sm=0;
    for(int i=0;i<n-1;i++)
        sm+=m[i];
    if(m[n-1]-sm<=1)
        return m[n-1]+sm;
    else{
        return 2*sm+1;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> proj(n,0);
    for(int i=0;i<n;i++){
        cin>>proj[i];
    }
    long long result=numberOfWeeks(proj);
    cout<<result<<endl;
    return 0;
}