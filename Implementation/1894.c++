#include <bits/stdc++.h>
using namespace std;

#define ll long long
int chalkReplacer(vector<int>& chalk, int k) {
    ll sum=0;
    int n=chalk.size();
    for(int i=0;i<n;i++){
        sum+=chalk[i];
        if(sum>k) return i;
    }
    int rem=k%sum;
    for(int i=0;i<n;i++){
        rem-=chalk[i];
        if(rem<0) return i;
    }
    return -1;
}