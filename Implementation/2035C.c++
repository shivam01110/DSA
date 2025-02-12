#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<int> permutation;
    
    // Odd numbers in descending order
    for (int i = n; i >= 1; i -= 2) {
        permutation.push_back(i);
    }
    
    // Even numbers in ascending order
    for (int i = 2; i <= n; i += 2) {
        permutation.push_back(i);
    }

    // Compute k based on operations to confirm maximum value
    long long k = permutation[0];
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            k &= permutation[i];
        } else {
            k |= permutation[i];
        }
    }

    cout << k << endl;
    for (int x : permutation) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
