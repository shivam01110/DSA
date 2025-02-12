#include <bits/stdc++.h>
using namespace std;

int help(int n) {
    int sig = 1;
    for (int p = 2; p * p <= n; ++p) {
        int cnt = 0;
        while (n % p == 0) {
            cnt++;
            n /= p;
        }
        if (cnt % 2 != 0) {
            sig *= p;
        }
    }
    if (n > 1) {
        sig *= n;
    }
    return sig;
}

long long cnt(int x, int y) {
    unordered_map<int, int> cx, cy;
    
    for (int i = 1; i <= x; i++) {
        int s = help(i);
        cx[s]++;
    }
    for (int j = 1; j <= y; j++) {
        int s = help(j);
        cy[s]++;
    }

    long long res = 0;
    for (const pair<int, int>& p : cx) {
        if (cy.find(p.first) != cy.end()) {
            res += (long long) p.second * cy[p.first];
        }
    }
    return res;
}

int main() {
    int x = 10, y = 15;
    cout << cnt(x, y) << endl;
    return 0;
}
