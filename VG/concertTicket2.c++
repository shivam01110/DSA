#include <bits/stdc++.h>
using namespace std;

long long min_cost(int m, int k) {
    const int N_MAX = 20;
    vector<int> T_n(N_MAX, 0);
    int total_tickets = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> heap;

    vector<long long> k_powers(N_MAX);
    for (int n = 0; n < N_MAX; n++) {
        k_powers[n] = pow(k, n);
    }

    for (int n = 0; n < N_MAX; n++) {
        long long MC_n = k_powers[n] * (2 * T_n[n] + 1);
        heap.push({MC_n, n});
    }

    while (total_tickets < m) {
        long long MC_n=heap.top().first;
        int n=heap.top().second;
        heap.pop();
        T_n[n]++;
        total_tickets++;

        long long MC_n_new = k_powers[n] * (2 * T_n[n] + 1);
        heap.push({MC_n_new, n});
    }

    long long total_cost = 0;
    for (int n = 0; n < N_MAX; n++) {
        if (T_n[n]) {
            total_cost += k_powers[n] * (T_n[n] * T_n[n]);
        }
    }

    return total_cost;
}

int main() {
    int m, k;
    cin >> m >> k;
    cout << min_cost(m, k) << endl;
    return 0;
}