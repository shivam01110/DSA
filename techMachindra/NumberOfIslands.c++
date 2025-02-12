#include <bits/stdc++.h>
using namespace std;

int dir[5] = {0, 1, 0, -1, 0};

// Helper function for DFS traversal and updating the boundaries
void dfs(vector<vector<int>>& grid, int i, int j, int& r, int& c, vector<vector<int>>& vis, int& left, int& right, int& up, int& down) {
    vis[i][j] = 1; // Mark the current cell as visited
    left = min(left, j);
    right = max(right, j);
    up = min(up, i);
    down = max(down, i);
    for (int d = 1; d < 5; d++) {
        int nr = i + dir[d - 1];
        int nc = j + dir[d];
        if (0 <= nr && nr < r && 0 <= nc && nc < c && grid[nr][nc] == 1 && vis[nr][nc] == 0) {
            dfs(grid, nr, nc, r, c, vis, left, right, up, down);
        }
    }
}

// Function to check whether the island is completely surrounded by water
bool surrounded(int l, int r, int u, int d, vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    int cnt=0;
    int boundary=0;
    // Check left boundary
    if (l > 0) {
        boundary+=1;
        bool valid=true;
        for (int i = max(0,u-1); i <=min(d+1,row-1); i++) {
            if (grid[i][l-1] == 1) {valid=false;break;}
        }
        if (valid)cnt++;
    }

    // Check right boundary
    if (r < col - 1) {
        boundary+=1;
        bool valid=true;
        for (int i = max(0,u-1); i <=min(d+1,row-1); i++) {
            if (grid[i][r+1] == 1) {valid=false;break;}
        }
        if (valid)cnt++;
    }

    // Check upper boundary
    if (u > 0) {
        boundary+=1;
        bool valid=true;
        for (int i = max(0,l-1); i <=min(col-1,r+1); i++) {
            if (grid[u-1][i] == 1) {valid=false;break;}
        }
        if (valid)cnt++;
    }

    // Check lower boundary
    if (d < row - 1) {
        boundary+=1;
        bool valid=true;
        for (int i = max(0,l-1); i <=min(col-1,r+1); i++) {
            if (grid[d+1][i] == 1) {valid=false;break;}
        }
        if (valid)cnt++;
    }
    return cnt==boundary;
}

// Function to count the number of islands completely surrounded by water
int numIslandsWithSizes(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> vis(row, vector<int>(col, 0));
    int cnt = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {
                int left = INT_MAX, right = INT_MIN, up = INT_MAX, down = INT_MIN;
                dfs(grid, i, j, row, col, vis, left, right, up, down);
                // cout<<left<<" "<<right<<" "<<up<<" "<<down<<" "<<endl; 
                if (surrounded(left, right, up, down, grid)) {
                    cnt++;
                    cout<<i<<" "<<j<<endl;
                    cout<<left<<" "<<up<<" "<<right<<" "<<down<<endl;
                }
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int out = numIslandsWithSizes(grid);
    cout << out << endl;
    return 0;
}
