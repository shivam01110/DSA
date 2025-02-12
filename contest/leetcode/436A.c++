#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Function to extract diagonal
        auto getDiagonal = [&](int row, int col) {
            vector<int> diag;
            while (row < n && col < n) {
                diag.push_back(grid[row][col]);
                row++;
                col++;
            }
            return diag;
        };

        // Function to place sorted diagonal back
        auto setDiagonal = [&](int row, int col, vector<int>& diag) {
            int i = 0;
            while (row < n && col < n) {
                grid[row][col] = diag[i++];
                row++;
                col++;
            }
        };

        // Sorting bottom-left diagonals (including middle) in non-increasing order
        for (int i = 0; i < n; i++) {
            vector<int> diag = getDiagonal(i, 0);
            sort(diag.rbegin(), diag.rend());  // Sort in descending order
            setDiagonal(i, 0, diag);
        }

        // Sorting top-right diagonals in non-decreasing order
        for (int j = 1; j < n; j++) {
            vector<int> diag = getDiagonal(0, j);
            sort(diag.begin(), diag.end());  // Sort in ascending order
            setDiagonal(0, j, diag);
        }

        return grid;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,7,3}, {9,8,2}, {4,5,6}};
    vector<vector<int>> sortedGrid = sol.sortMatrix(grid);

    // Print the result
    for (auto& row : sortedGrid) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }

    return 0;
}
