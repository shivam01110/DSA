#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Function to calculate GCD of two numbers
    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Function to calculate LCM of two numbers
    ll lcm(ll a, ll b) {
        return (a / gcd(a, b)) * b;
    }

    // Function to find GCD of an array
    ll findGCD(vector<int>& arr,ll l,ll r) {
        ll result = arr[l];
        for (ll i = l; i < r; i++) {
            result = gcd(result, arr[i]);
            if (result == 1) break; // Early exit if GCD becomes 1
        }
        return result;
    }

    // Function to find LCM of an array
    ll findLCM(vector<int>& arr,ll l,ll r) {
        ll result = arr[l];
        for (ll i = l; i < r; i++) {
            result = lcm(result, arr[i]);
        }
        return result;
    }
    bool prod(vector<int>& arr,ll l,ll r) {
        ll result = 1;
        int upperlim=findLCM(arr,l,r)*findGCD(arr,l,r);
        for (ll i = l; i < r; i++) {
            result = result*arr[i];
            if(result>upperlim) return 0;
        }
        return (upperlim==result);
    }
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int res=n;
        for(;res>1;res--){
            int l=0,r=l+res;
            while(r<=n){
                if(prod(nums,l,r)) return res;
                l++;
                r++;
            }
        }
        return 1;
    }
};