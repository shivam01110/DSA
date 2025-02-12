#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

// Function to calculate (n^k) % mod using Modular Exponentiation
int calpow(int n, int k) {
    int res = 1;
    n = n % mod; // Handle cases where n >= mod
    while (k > 0) {
        // If k is odd, multiply n with result
        if (k & 1) {
            res = (1LL * res * n) % mod;
        }
        // Square n and reduce k by half
        n = (1LL * n * n) % mod;
        k >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    int n, k;
    while (t--) {
        cin >> n >> k;
        cout << calpow(n, k) << endl;
    }
    return 0;
}
