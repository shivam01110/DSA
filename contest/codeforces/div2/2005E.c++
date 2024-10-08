#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002; 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2, 0));
    vector<vector<pair<int, int>>> cells_by_value(8); 
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= m; ++col) {
            int value;
            cin >> value;
            if (value >= 1 && value <= 7) {
                cells_by_value[value].emplace_back(row, col);
                grid[row][col] = value;
            }
        }
    }
    vector<int> sequence(7);
    for (int i = 0; i < 7; ++i) {
        cin >> sequence[i];
    }
    vector<vector<bool>> future_possible(n + 2, vector<bool>(m + 2, false));
    vector<vector<bool>> current_possible(n + 2, vector<bool>(m + 2, false));
    for (int k = 6; k >= 0; --k) {
        int value = sequence[k];
        for (auto p : cells_by_value[value]) {
            if (!future_possible[p.first + 1][p.second + 1]) {
                current_possible[p.first][p.second] = true;
            }
        }
        for (int r = n; r >= 1; --r) {
            for (int c = m; c >= 1; --c) {
                current_possible[r][c] =current_possible[r][c] | ((current_possible[r + 1][c] || current_possible[r][c + 1]));
            }
        }
        future_possible = current_possible;
        fill(current_possible.begin(), current_possible.end(), vector<bool>(m + 2, false));
    }

    if (future_possible[1][1]) {
        cout << 'T' << endl;
    } else {
        cout << 'N' << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
