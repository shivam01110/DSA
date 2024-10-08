//Sieve of Eratosthenes
//TC->O(nlog(log(n)))
//SC->O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int> prime(n+1,1);
        prime[0]=0;prime[1]=0;
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
        return prime[n-1];
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    cout<<sol.countPrimes(n)<<endl;
    return 0;
}