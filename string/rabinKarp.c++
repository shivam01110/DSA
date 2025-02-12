
//using 2 hash function the chance of spurious hits can be reduced to 10^-10;


#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD1=1e9+7;
const ll MOD2=1e9+33;
const ll RADIX1=26;
const ll RADIX2=28;

ll CalHashValue(string str,ll radix,ll m,ll mod){
    ll hash=0,factor=1;
    for(int i=m-1;i>=0;i--){
        hash+=((str[i]-'a')*factor)%mod;
        factor=(factor*radix)%mod;
    }
    return hash%mod;
}

int RabinKarp(string str,string pattern){
    int m=pattern.length(),n=str.length();
    if(n<m) return -1;
    ll MaxWeight1=1,MaxWeight2=1;
    for(int i=1;i<=m;i++){
        MaxWeight1=(MaxWeight1*RADIX1)%MOD1;
        MaxWeight2=(MaxWeight2*RADIX2)%MOD2;
    }
    ll hash1=CalHashValue(pattern,RADIX1,m,MOD1);
    ll hash2=CalHashValue(pattern,RADIX2,m,MOD2);
    ll hashFun1=0,hashFun2=0;
    for(int i=0;i<n-m+1;i++){
        if(i==0){
            hashFun1=CalHashValue(str,RADIX1,m,MOD1);
            hashFun2=CalHashValue(str,RADIX2,m,MOD2);
        }
        else{
            hashFun1=((hashFun1*RADIX1)%MOD1-((str[i-1]-'a')*MaxWeight1)%MOD1+(str[i+m-1]-'a')+MOD1)%MOD1;
            hashFun2=((hashFun2*RADIX2)%MOD2-((str[i-1]-'a')*MaxWeight2)%MOD2+(str[i+m-1]-'a')+MOD2)%MOD2;
        }
        if(hashFun1==hash1 && hashFun2==hash2) return i;
    }
    return -1;
}