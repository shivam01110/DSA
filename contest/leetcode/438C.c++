#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    long long printNcR(int n, int r)
    {
    
        // p holds the value of n*(n-1)*(n-2)...,
        // k holds the value of r*(r-1)...
        long long p = 1, k = 1;
    
        // C(n, r) == C(n, n-r),
        // choosing the smaller value
        if (n - r < r)
            r = n - r;
    
        if (r != 0) {
            while (r) {
                p =(p*n);
                k =(k*r);
    
                // gcd of p, k
                long long m = __gcd(p, k);
    
                // dividing by gcd, to simplify
                // product division by their gcd 
                // saves from the overflow
                p /= m;
                k /= m;
    
                n--;
                r--;
            }
    
            // k should be simplified to 1
            // as C(n, r) is a natural number
            // (denominator should be 1 ) .
        }
    
        else
            p = 1;
    
        // if our approach is correct p = ans and k =1
        return p;
    }
    bool hasSameDigits(string s) {
        int l=s.length();
        int n=l-2;
        vector<int> ncr(n+1,1);
        for(int i=0;i<=n/2;i++){
            ncr[i]=printNcR(n,i);
            ncr[n-i]=ncr[i];
        }
        int first=0;
        int sec=0;
        for(int i=0;i<l-1;i++){
            int sum=((s[i]-'0')*ncr[i])%10;
            first=(first+sum)%10;
        }
        for(int i=1;i<l;i++){
            int sum=((s[i]-'0')*ncr[i-1])%10;
            sec=(sec+sum)%10;
        }
        return first==sec;
    }
};


int main(){
    Solution sol;
    for(int i=0;i<=9;i++){
        cout<<sol.printNcR(9,i)<<" ";
    }
    return 0;
}