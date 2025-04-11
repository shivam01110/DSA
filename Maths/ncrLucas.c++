// Luca's Theorem for finding nCr

/*
For a prime 𝑝,the binomial coefficient 𝐶(𝑛,𝑟) modulo 𝑝 can be computed as:
𝐶(𝑛,𝑟)mod 𝑝=𝐶(𝑛0,𝑟0)×𝐶(𝑛1,𝑟1)×𝐶(𝑛2,𝑟2)×...mod  𝑝
where:
    𝑛0,𝑛1,𝑛2,…are the digits of 𝑛 in base 𝑝,
    𝑟0,𝑟1,𝑟2,…are the digits of 𝑟 in base 𝑝.
If at any position 𝑟𝑖 > 𝑛𝑖, then 𝐶(𝑛,𝑟)≡ 0 mod 𝑝, meaning the binomial coefficient is divisible by 𝑝.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lucas(int n,int r,int p){//p->prime
        int ncr=1;
        while(n!=0 || r!=0){
            int ni=n%p; //n0,n1,n2,.... are the digits of n in base p
            int wi=r%p; //r0,r1,r2,.... are the digits of r in base p
            if(wi>ni) return 0;
            n=n/p;
            r=r/p;
            ncr=(ncr*findNcR(ni,wi))%p;
        }
        return ncr;
    }
    int findRem(int rem2,int rem5){
        for(int rem=0;rem<10;rem++){
            if(rem%2==rem2 && rem%5==rem5) return rem;
        }
        return -1;
    }
    int findNcR(int n, int r){
        // p holds the value of n*(n-1)*(n-2)...,
        // k holds the value of r*(r-1)...
        int p = 1, k = 1;
        if (n - r < r) r = n - r;   // C(n, r) == C(n, n-r), choosing the smaller value
        if (r != 0) {
            while (r) {
                p =(p*n);
                k =(k*r);
                // gcd of p, k
                int m = __gcd(p, k);
                // dividing by gcd, to simplify product division by their gcd saves from the overflow
                p /= m;
                k /= m;
                n--;
                r--;
            }
            // k should be simplified to 1 as C(n, r) is a natural number (denominator should be 1 ) .
        }
        else p = 1;
        return p;
    }
    bool hasSameDigits(string s) {
        int l=s.length();
        int n=l-2;
        int digit1=0,digit2=0;
        for(int i=1;i<l;i++){
            int d1=(s[i-1]-'0'),d2=(s[i]-'0');
            int ncr2=lucas(n,i-1,2),ncr5=lucas(n,i-1,5);
            int mul=findRem(ncr2,ncr5);
            digit1=(digit1+mul*d1)%10;
            digit2=(digit2+mul*d2)%10;
        }
        return digit1==digit2;
    }   
};


int main(){
    Solution sol;
    cout<<sol.lucas(9,3,2)<<endl;
    return 0;

}