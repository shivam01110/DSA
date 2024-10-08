//Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int  n=sqrt(r);
        vector<int> prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i<=sqrt(n);i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<=n;i++){
            prime[i]+=cnt;
            cnt=prime[i];
        }
        int left=prime[sqrt(l-1)];
        int right=prime[sqrt(r)];
        return r-l+1-(right-left);
    }
};