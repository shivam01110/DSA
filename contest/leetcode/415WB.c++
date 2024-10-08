#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long maxScore(vector<int>& a, vector<int>& b) {
    ll m1=LLONG_MIN,m2=LLONG_MIN,m3=LLONG_MIN,m4=LLONG_MIN;
    for(int i=0;i<b.size();i++){
        m4=max(m4,(ll)m3+b[i]*a[3]);
        m3=max(m2,(ll)m2+b[i]*a[2]);
        m2=max(m2,(ll)m1+b[i]*a[1]);
        m1=max(m1,(ll)b[i]*a[0]);
    }
    return m4;
}