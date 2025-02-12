#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long floydWarshallSum(int n, vector<vector<long long>>& cost) {
    vector<vector<long long>> dist = cost;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dist[i][j] != LLONG_MAX) {
                sum += dist[i][j];
            }
        }
    }

    return sum;
}

void calcCosts(int n, vector<vector<int>>& tc, int m, vector<vector<int>>& wu) {
    vector<vector<long long>> cost(n + 1, vector<long long>(n + 1, LLONG_MAX));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cost[i][j] = 0;
            } else if (tc[i - 1][j - 1] != -1) {
                cost[i][j] = tc[i - 1][j - 1];
            }
        }
    }

    vector<long long> res;

    for (auto& u : wu) {
        int x = u[0], y = u[1], c = u[2];

        long long origXY = cost[x][y];
        long long origYX = cost[y][x];
        cost[x][y] = min(cost[x][y], (long long)c);
        cost[y][x] = min(cost[y][x], (long long)c);

        res.push_back(floydWarshallSum(n, cost));

        cost[x][y] = origXY;
        cost[y][x] = origYX;
    }

    for (long long r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;

    vector<vector<int>> tc(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tc[i][j];
        }
    }

    cin >> m;
    vector<vector<int>> wu(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> wu[i][0] >> wu[i][1] >> wu[i][2];
    }

    calcCosts(n, tc, m, wu);

    return 0;
}
// n - devices waala hai ye