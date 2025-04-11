#include <bits/stdc++.h>
using namespace std;


#define ll long long

class Solution {
public:
    vector<ll> presum,num;
    //sum till x
    ll compute(int x){
        int i=0;
        for(;num[i]<=x;){
            i++;
        }
        ll res=presum[i]-(num[i]-x)*i;
        return res;
    }
    //do precomputation
    void precomputation(){
        presum.push_back(0);
        num.push_back(0);
        ll n=1,p=0,prev=0,tot=0;
        while(p<=15){       //4^15>1e9
            n=n*4;
            p++;
            tot=tot+(n-1-prev)*p;
            prev=n-1;
            presum.push_back(tot);
            num.push_back(n-1);
        }
    }
    long long minOperations(vector<vector<int>>& queries) {
        precomputation();
        ll ops=0;
        for(auto q:queries){
            int l=q[0],r=q[1];
            ll sumr=compute(r);
            ll suml=compute(l-1);
            ll range=sumr-suml;
            ll op=(range+1)/2;
            ops+=op;
        }
        return ops;
    }
};