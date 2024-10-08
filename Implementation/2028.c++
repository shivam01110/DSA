#include <bits/stdc++.h>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m=rolls.size();
    int total=(m+n)*mean;
    for(int i=0;i<m;i++){
        total-=rolls[i];
    }
    if(total>n*6 || total<n) return {};
    int MissingMean=total/n;
    vector<int> missing(n,MissingMean);
    total=total-(MissingMean*n);
    for(int i=0;i<total;i++){
        missing[i]++;   //increase the (total) number of element in missing vector so that overall mean is achived
    }
    return missing;
}