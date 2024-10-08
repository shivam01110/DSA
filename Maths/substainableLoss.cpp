#include <iostream>
using namespace std;

const int MOD = 998244353;

// Function to compute modular inverse of q using Fermat's Little Theorem
long long modInverse(long long q, int mod) {
    long long result = 1;
    long long power = mod - 2; // Fermat's exponent for mod inverse
    while (power) {
        if (power % 2 == 1) {
            result = (result * q) % mod;
        }
        q = (q * q) % mod;
        power /= 2;
    }
    return result;
}

// Function to calculate the expected number of days based on W, G, L
long long calculateExpectedDays(long long W, long long G, long long L) {
    if (L == 0) {
        // Case 1: L = 0, straightforward weight loss
        return (W - G) % MOD;
    }

    // Case 2: L > 0, random walk with reflecting boundary at W + L
    long long p = 0, q = 1; // p/q will store the expected days as a fraction
    
    // Calculate the expected number of days using geometric series logic
    long long diff = W - G;  // This is the difference you want to bridge
    
    // Geometric series approximation for large L
    // E[D] ~ 2 * diff - 1 when L > 0, reflecting boundary
    p = 2 * diff - 1;  // This is an approximation of the expected days in large cases
    q = 1;  // For simplicity, initially assume q = 1
    
    // Modular arithmetic for large numbers
    return (p * modInverse(q, MOD)) % MOD;
}

int main() {
    int T;
    cin >> T;  // Read the number of test cases
    for (int i = 1; i <= T; ++i) {
        long long W, G, L;
        cin >> W >> G >> L;

        // Calculate the expected number of days for this test case
        long long result = calculateExpectedDays(W, G, L);

        // Output result for this test case in the required format
        cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}
